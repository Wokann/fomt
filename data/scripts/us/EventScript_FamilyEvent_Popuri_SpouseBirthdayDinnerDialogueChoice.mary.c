#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWithWork[] =
        "Are you done with work?{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_Yes[] =
        "Yes";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_No[] =
        "No";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs[] =
        "You know what day it is\r\n"
        "today, right...?{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Our anniversary";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_MyBirthday[] =
        "My birthday";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YourBirthday[] =
        "Your birthday";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_ItsMyBirthdayHowCanYou[] =
        "It's my birthday!!\r\n"
        "How can you forget both my\r\n"
        "birthday and our{Press}\r\n"
        "anniversary!?{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "I'd better apologize \r\n"
        "later...{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_WhatItsMyBirthdayTodayYou[] =
        "What!? \r\n"
        "It's my birthday today,\r\n"
        "you idiot!{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YouRememberedIDontKnowWhy[] =
        "You remembered!\r\n"
        "I don't know why, but I was\r\n"
        "sure you'd forget...Sorry!{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_ILookMoreMatureToYou[] =
        "I look more mature to\r\n"
        "you, don't I...?{Press}\p"
        "Well, one day does too\r\n"
        "make a difference!{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}'s birthday";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_WhatKindOfAFatherAre[] =
        "What kind of a father \r\n"
        "are you!? {Press}\p"
        "How can you forget both\r\n"
        "{Baby}'s birthday\r\n"
        "and mine!?{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Hurry up and finish.\r\n"
        "Today is an important day.{Press}";
};

void EventScript_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_POPURI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_ItsMyBirthdayHowCanYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_WhatItsMyBirthdayTodayYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_POPURI, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YouRememberedIDontKnowWhy);
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
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_ILookMoreMatureToYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_WhatItsMyBirthdayTodayYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_POPURI, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YouRememberedIDontKnowWhy);
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
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_ILookMoreMatureToYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_WhatKindOfAFatherAre);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
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
            TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
}

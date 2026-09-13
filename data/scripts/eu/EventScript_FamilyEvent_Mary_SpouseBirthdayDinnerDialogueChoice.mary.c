#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking[] =
        "Are you done with work?{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_Yes[] =
        "Yes";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_No[] =
        "No";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_DoesThisRemindYouOfSomething[] =
        "Does this remind you of\r\n"
        "something?{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Our anniversary";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_MyBirthday[] =
        "My birthday";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_YourBirthday[] =
        "Your birthday";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_OurAnniversaryHuhInThatCase[] =
        "Our anniversary, huh?{Press}\p"
        "In that case...just when do\r\n"
        "you think my birthday is!?{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "I'd better apologize \r\n"
        "later...{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_CorrectsPlayerBirthdayAnswerBeforeChildbirth[] =
        "Ha! Sometimes you really are\r\n"
        "like a character in a story!\r\n"
        "It's my birthday, silly!{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ThatsRightTodayImAYear[] =
        "That's right. \r\n"
        "Today I'm a year older, and\r\n"
        "hopefully a year wiser. {Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday[] =
        "It's no fun having your \r\n"
        "birthday be the same day as\r\n"
        "your parents' anniversary!{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}'s birthday";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_CorrectsPlayerBirthdayAnswerAfterChildbirth[] =
        "Ha! Sometimes you really are\r\n"
        "like a character in a story!\r\n"
        "It's my birthday, silly{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_WhatKindOfAFatherDoesn[] =
        "What kind of a father\r\n"
        "doesn’t know his own son's\r\n"
        "or his own wife's birthday?!{Press}\p"
        "Today is MY birthday!{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Hurry up and finish.\r\n"
        "Today is an important day.{Press}";
};

void EventScript_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_MARY);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_DoesThisRemindYouOfSomething);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_OurAnniversaryHuhInThatCase);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_CorrectsPlayerBirthdayAnswerBeforeChildbirth);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_MARY, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ThatsRightTodayImAYear);
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
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_CorrectsPlayerBirthdayAnswerAfterChildbirth);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_MARY, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ThatsRightTodayImAYear);
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
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_WhatKindOfAFatherDoesn);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
}

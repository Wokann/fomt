#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_GooGoo[] =
        "Goo-goo.{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_Yes[] =
        "Yes";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_No[] =
        "No";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YouThinkThisMealIsDifferent[] =
        "You think this meal is \r\n"
        "different from what I \r\n"
        "usually cook?{Press}\p"
        "That's because today is \r\n"
        "special! Do you know why?{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Our anniversary";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_MyBirthday[] =
        "My birthday";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YourBirthday[] =
        "Your birthday";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_OurAnniversaryYouWereJustKidding[] =
        "...Our anniversary?\r\n"
        "You were just kidding, \r\n"
        "right? I hope you'd{Press}\r\n"
        "remember your own birthday!{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "I'd better apologize \r\n"
        "later...{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_PlayerSurprisesElliForHerBirthday[] =
        "Happy birthday!\r\n"
        "Are you surprised?{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_ICantWaitToHaveA[] =
        "I can't wait to have a\r\n"
        "baby. I love kids. {Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_WellMaybeIShouldntExpectYou[] =
        "Well, maybe I shouldn't\r\n"
        "expect you to remember MY\r\n"
        "birthday, but at least {Press}\r\n"
        "remember your OWN!{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}'s birthday";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_NowYoureAYearOlderAnd[] =
        "Now you're a year older and\r\n"
        "a dad as well, so it's time\r\n"
        "to stop goofing around!{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YouReallyAreAStrangeOne[] =
        "You really are a strange one,\r\n"
        "aren't you?{Press}\p"
        "How many people forget both\r\n"
        "their own and their child's\r\n"
        "birthday...?{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Hurry up and finish.\r\n"
        "Today is an important day.{Press}";
};

void EventScript_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ELLI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_GooGoo);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YouThinkThisMealIsDifferent);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_OurAnniversaryYouWereJustKidding);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ELLI, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_PlayerSurprisesElliForHerBirthday);
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
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_ICantWaitToHaveA);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_WellMaybeIShouldntExpectYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ELLI, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_PlayerSurprisesElliForHerBirthday);
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
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_NowYoureAYearOlderAnd);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_WellMaybeIShouldntExpectYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YouReallyAreAStrangeOne);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
}

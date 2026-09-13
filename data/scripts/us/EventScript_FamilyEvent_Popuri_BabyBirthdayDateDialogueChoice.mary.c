#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork[] =
        "Are you done with work?{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_Yes[] =
        "Yes";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_No[] =
        "No";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YouDoKnowWhatDayIt[] =
        "You do know what day it is,\r\n"
        "don't you?{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_MyBirthday[] =
        "My birthday.";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YourBirthday[] =
        "Your birthday.";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}'s birthday.";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YoureKiddingRightItsBabyS[] =
        "You're kidding...right?\r\n"
        "It's {Baby}'s \r\n"
        "birthday, you idiot!{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "I'd better apologize \r\n"
        "later...{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_OfCourseItIsWhatYou[] =
        "Of course it is!\r\n"
        "What, you say he can't eat\r\n"
        "this yet? {Press}\p"
        "Don't worry, I'll take \r\n"
        "care of that!{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_HeSeemsToBeGettingBigger[] =
        "He seems to be getting\r\n"
        "bigger and stronger by the\r\n"
        "day!...{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Hurry up and finish.\r\n"
        "Today is an important day.{Press}";
};

void EventScript_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_POPURI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YouDoKnowWhatDayIt);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YourBirthday, gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_BabySBirthday);
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
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YoureKiddingRightItsBabyS);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_POPURI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_POPURI);
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YoureKiddingRightItsBabyS);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_POPURI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_POPURI, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_POPURI);
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_OfCourseItIsWhatYou);
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
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_HeSeemsToBeGettingBigger);
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
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_POPURI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
}

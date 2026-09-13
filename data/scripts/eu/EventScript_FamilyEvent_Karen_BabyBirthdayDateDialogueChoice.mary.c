#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork[] =
        "Are you done with work?{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_Yes[] =
        "Yes";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_No[] =
        "No";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_DoesntThisCakeLookGoodYou[] =
        "Doesn't this cake look good?\r\n"
        "You know why I baked it, \r\n"
        "right?{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_MyBirthday[] =
        "My birthday.";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_YourBirthday[] =
        "Your birthday.";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}'s birthday.";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantBelieveYouWouldConfuse[] =
        "I can't believe you would\r\n"
        "confuse your own birthday \r\n"
        "with your son's!{Press}\p"
        "You really are funny, \r\n"
        "{NickName}.{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "I'd better apologize \r\n"
        "later...{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ThanksForThinkingAboutMeBut[] =
        "Thanks for thinking about\r\n"
        "me, but aren't you \r\n"
        "forgetting {Baby}?{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabyIsLuckyToHaveSuch[] =
        "{Baby} is lucky\r\n"
        "to have such a considerate\r\n"
        "father!{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantWaitUntilHeGrows[] =
        "I can't wait until he grows\r\n"
        "up and we can go out \r\n"
        "on the town together!{Press}\p"
        "His father sure won't\r\n"
        "take me...{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Hurry up and finish.\r\n"
        "Today is an important day.{Press}";
};

void EventScript_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_KAREN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_DoesntThisCakeLookGoodYou);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_MyBirthday, gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_YourBirthday, gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabySBirthday);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantBelieveYouWouldConfuse);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ThanksForThinkingAboutMeBut);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_KAREN, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabyIsLuckyToHaveSuch);
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
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantWaitUntilHeGrows);
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
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
}

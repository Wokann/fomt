#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_AreYouDoneWorking[] =
        "Are you done with work?{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_Yes[] =
        "Yes";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_No[] =
        "No";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_DoesThisRemindYouOfAnything[] =
        "Does this remind you of \r\n"
        "anything?{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_MyBirthday[] =
        "It's my birthday.";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_ItsYourBirthday[] =
        "It's your birthday.";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}'s birthday.";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_VeryFunnySometimesIThinkYou[] =
        "Very funny. Sometimes I \r\n"
        "think you really are like a \r\n"
        "character in a novel.{Press}\p"
        "It's {Baby}'s\r\n"
        "birthday, of course.{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "I'd better apologize \r\n"
        "later...{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_WhatAreYouTalkingAboutI[] =
        "What are you talking about!?\r\n"
        "I can't believe you've \r\n"
        "forgotten it's{Press}\r\n"
        "{Baby}'s birthday!{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_YoureAGraetFatherNickNameThanks[] =
        "You're a graet father,\r\n"
        "{NickName}. {Press}\p"
        "Thanks for remembering \r\n"
        "{Baby}'s birthday.{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_ItsNoFunHavingYourBirthday[] =
        "It's no fun having your \r\n"
        "birthday be the same day as\r\n"
        "your parents' anniversary!{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Hurry up and finish.\r\n"
        "Today is an important day.{Press}";
};

void EventScript_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_MARY);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_AreYouDoneWorking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_DoesThisRemindYouOfAnything);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_MyBirthday, gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_ItsYourBirthday, gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_BabySBirthday);
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
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_VeryFunnySometimesIThinkYou);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_MARY);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_MARY);
                    SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                    ShowTalkHeartIndicator(CHARACTER_MARY);
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_WhatAreYouTalkingAboutI);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_MARY);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_MARY, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_MARY);
                    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_MARY);
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_YoureAGraetFatherNickNameThanks);
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
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_ItsNoFunHavingYourBirthday);
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
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_MARY);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
}

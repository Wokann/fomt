#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork[] =
        "Are you done with work?{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_Yes[] =
        "Yes";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_No[] =
        "No";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IDontUsuallyBakeCakesBut[] =
        "I don't usually bake cakes, \r\n"
        "but surely you know why I\r\n"
        "did today, right?{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsMyBirthday[] =
        "It's my birthday.";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsYourBirthday[] =
        "It's your birthday.";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}'s birthday.";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouBecomingSenileAlreadyI[] =
        "Are you becoming senile \r\n"
        "already...? I hope not!{Press}\p"
        "It's {Baby}'s\r\n"
        "birthday, silly!{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "I'd better apologize \r\n"
        "later...{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ImFlatteredYoureThinkingOfMe[] =
        "I'm flattered you're \r\n"
        "thinking of me, but it's {Press}\r\n"
        "your son's birthday, \r\n"
        "not mine, silly!{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_OfCourseYouRememberBabyS[] =
        "Of course you remember\r\n"
        "{Baby}'s birthday!\r\n"
        "Who could forget their own{Press}\r\n"
        "son's birthday!{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IEnjoyWatchingHimGrowUp[] =
        "I enjoy watching him \r\n"
        "grow up, don't you?{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Hurry up and finish.\r\n"
        "Today is an important day.{Press}";
};

void EventScript_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ELLI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IDontUsuallyBakeCakesBut);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsMyBirthday, gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsYourBirthday, gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_BabySBirthday);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouBecomingSenileAlreadyI);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
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
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ImFlatteredYoureThinkingOfMe);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_ELLI, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_OfCourseYouRememberBabyS);
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
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IEnjoyWatchingHimGrowUp);
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
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
}

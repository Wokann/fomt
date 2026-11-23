#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0614_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice.mary.h"

void EventScript_0614_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ANN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_TodayIsASpecialDayYou);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_MyBirthday, gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_YourBirthday, gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_BabySBirthday);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_HowCanYouForgetYourOwn);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AreYouSureYoureNotWorking);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_ANN, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_OfCourseYouWouldRememberBaby);
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
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AYearGoesSoQuicklyI);
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
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
}

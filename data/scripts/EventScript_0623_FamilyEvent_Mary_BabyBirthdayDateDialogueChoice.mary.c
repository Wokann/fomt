#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0623_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice.mary.h"

void EventScript_0623_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice(void)
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
                    CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
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
                    CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
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
                    CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
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

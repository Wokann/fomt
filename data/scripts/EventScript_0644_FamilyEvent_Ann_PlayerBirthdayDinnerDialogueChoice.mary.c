#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0644_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice.mary.h"

void EventScript_0644_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ANN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_WorkCompletionPrompt);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_SorryTryAgainItsYourOwn);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ANN, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_ThatsRightYoureGettingOlderNow);
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
                        SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_SorryAllMyFoodIsThe);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_MyBirthdayGetAGripIts);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ANN, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
#if defined(UNIFY_REGIONS) || defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_ThatsRightYoureGettingOlderNow);
#elif defined(REGION_DE)
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_ThatsRightYoureGettingOlderNow_2);
#endif
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
                        SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_SorryAllMyFoodIsThe);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_MyBirthdayGetAGripIts);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_StopFoolingMeIKnowYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
}

#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_NickNameWhereAreYouGoing[] =
        "{NickName},\r\n"
        "where are you going{Press}?";

    const char gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_PlayerWhereAreYouGoing[] =
        "{Player},\r\n"
        "where are you going{Press}?";

    const char gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_YouCantTakeYourEyesOff[] =
        "You can't take your eye's \r\n"
        "off of{Baby}.{Press}";

    const char gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_ChoiceTakeBath[] =
        "Take a bath?";

    const char gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_Yes[] =
        "Yes";

    const char gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_No[] =
        "No";
};

void EventScript_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice(void)
{
    int var_0;
    if (VarGet(VAR_POPURI_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_NickNameWhereAreYouGoing);
        TalkClose();
        return;
    }
    else
    {
        if (VarGet(VAR_ANN_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_NickNameWhereAreYouGoing);
            TalkClose();
            return;
        }
        else
        {
            if (VarGet(VAR_ELLI_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_ELLI);
                ShowTalkHeartIndicator(CHARACTER_ELLI);
                TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_NickNameWhereAreYouGoing);
                TalkClose();
                return;
            }
            else
            {
                if (VarGet(VAR_KAREN_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_NickNameWhereAreYouGoing);
                    TalkClose();
                    return;
                }
                else
                {
                    if (VarGet(VAR_MARY_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_NickNameWhereAreYouGoing);
                        TalkClose();
                        return;
                    }
                    else
                    {
                        if (VarGet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                        {
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                            TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_PlayerWhereAreYouGoing);
                            TalkClose();
                            return;
                        }
                        else
                        {
                            if (VarGet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                            {
                                TalkOpen();
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                SetTalkNameplateCharacter(CHARACTER_POPURI);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_PlayerWhereAreYouGoing);
                                TalkClose();
                                return;
                            }
                            else
                            {
                                if (VarGet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                {
                                    TalkOpen();
                                    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
                                    SetTalkNameplateCharacter(CHARACTER_ANN);
                                    ShowTalkHeartIndicator(CHARACTER_ANN);
                                    TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_PlayerWhereAreYouGoing);
                                    TalkClose();
                                    return;
                                }
                                else
                                {
                                    if (VarGet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                    {
                                        TalkOpen();
                                        SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
                                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                                        TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_PlayerWhereAreYouGoing);
                                        TalkClose();
                                        return;
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                        {
                                            TalkOpen();
                                            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                                            SetTalkNameplateCharacter(CHARACTER_KAREN);
                                            ShowTalkHeartIndicator(CHARACTER_KAREN);
                                            TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_PlayerWhereAreYouGoing);
                                            TalkClose();
                                            return;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                            {
                                                TalkOpen();
                                                SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                                                SetTalkNameplateCharacter(CHARACTER_MARY);
                                                ShowTalkHeartIndicator(CHARACTER_MARY);
                                                TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_PlayerWhereAreYouGoing);
                                                TalkClose();
                                                return;
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_FAMILY_EVENING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                                {
                                                    TalkOpen();
                                                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                                                    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                                                    TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_PlayerWhereAreYouGoing);
                                                    TalkClose();
                                                    return;
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_HARVEST_GODDESS_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                                    {
                                                        TalkOpen();
                                                        TalkMessage(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_YouCantTakeYourEyesOff);
                                                        TalkClose();
                                                        return;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    TalkOpen();
    var_0 = TalkPromptChoice2(gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_ChoiceTakeBath, gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_Yes, gText_LocationInteraction_FarmhouseBathroomUseAndFamilyExitChoice_No);
    TalkClose();
    if (var_0 == PROMPT_CHOICE_OPTION_2)
    {
        return;
    }
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    OpenDoor(DOOR_SLOT_12);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(20), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    MoveEntityYTo(ENTITY_PLAYER, Y(52), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    ChangePlayerStaminaAndFatigue(20, mary_negated_int(-20));
    PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
    WaitFrames(10);
    PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
    WaitFrames(10);
    PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
    WaitFrames(120);
    PlaySong(AUDIO_START, AUDIO_SFX_THROWN_ITEM_LANDS);
    WaitFrames(60);
    if (VarGet(VAR_HOUR) == 5 && VarGet(VAR_MINUTE) >= 30)
    {
        CloseDoor(DOOR_SLOT_12);
        SetGameTime(6, 0);
        ClearPreservedPlayerLocation();
        ChangePlayerStaminaAndFatigue(0, 10);
        CallScript(EventScript_SystemEvent_AdvanceToNextDay);
    }
    else
    {
        if (VarGet(VAR_MINUTE) >= 30)
        {
            if (VarGet(VAR_HOUR) == 23)
            {
                SetGameTime(0, VarGet(VAR_MINUTE) - 30);
            }
            else
            {
                SetGameTime(VarGet(VAR_HOUR) + 1, VarGet(VAR_MINUTE) - 30);
            }
        }
        else
        {
            SetGameTime(VarGet(VAR_HOUR), VarGet(VAR_MINUTE) + 30);
        }
    }
    SetEntityPosition(ENTITY_PLAYER, X(20), Y(52), FACING_DOWN);
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(64), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    CloseDoor(DOOR_SLOT_12);
}

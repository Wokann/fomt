#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterInnBackRoomWithEventDispatch_DoorIsLocked[] =
        "It's locked...{Press}";

    const char gText_LocationTransition_EnterInnBackRoomWithEventDispatch_DougBlocksUnauthorizedEntry[] =
        "Please don't go in there!{Press}";
};

void EventScript_LocationTransition_EnterInnBackRoomWithEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_6 = FALSE;
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        var_2 = VarGet(VAR_DAY_OF_WEEK);
        var_4 = VarGet(VAR_WEATHER_TODAY);
        var_5 = VarGet(VAR_YEAR);
        if (VarGet(VAR_ANN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            var_6 = FALSE;
        }
        else
        {
            if (VarGet(VAR_ANN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                var_6 = FALSE;
            }
            else
            {
                if (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    var_6 = FALSE;
                }
                else
                {
                    if (VarGet(VAR_ANN_MOTHERS_DEATH_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        var_6 = FALSE;
                    }
                    else
                    {
                        if (VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                        {
                            var_6 = FALSE;
                        }
                        else
                        {
                            if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                var_6 = TRUE;
                            }
                            else
                            {
                                if (GetNpcFriendship(CHARACTER_DOUG) <= 100)
                                {
                                    var_6 = FALSE;
                                }
                                else
                                {
                                    if (GetNpcFriendship(CHARACTER_DOUG) > 100)
                                    {
                                        var_6 = FALSE;
                                        if (GetNpcFriendship(CHARACTER_DOUG) > 200)
                                        {
                                            var_6 = TRUE;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (var_6 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            OpenDoor(DOOR_SLOT_1);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_INN_BACK_ROOM, X(92), Y(320));
            SetEntityPosition(ENTITY_PLAYER, X(92), Y(320), FACING_UP);
            if (VarGet(VAR_ANN_GIVES_DOUG_BIRTHDAY_PRESENT_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_11 && (var_3 >= 19 && var_3 < 21) && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && HasMetNpc(CHARACTER_ANN) == TRUE && HasMetNpc(CHARACTER_DOUG) == TRUE && GetEntityLocation(ENTITY_ANN) == MAP_INN_1F && GetEntityLocation(ENTITY_DOUG) == MAP_INN_BACK_ROOM)
            {
                VarSet(VAR_ANN_GIVES_DOUG_BIRTHDAY_PRESENT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                CallScript(EventScript_FamilyEvent_Doug_BirthdayGiftFromAnn);
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            if (VarGet(VAR_ANN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_MOTHERS_DEATH_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || GetEntityLocation(ENTITY_DOUG) != MAP_INN_1F)
            {
                TalkMessage(gText_LocationTransition_EnterInnBackRoomWithEventDispatch_DoorIsLocked);
            }
            else
            {
                SetTalkPortrait(TALK_PORTRAIT_DOUG_ANGRY);
                SetTalkNameplateCharacter(CHARACTER_DOUG);
                TalkMessage(gText_LocationTransition_EnterInnBackRoomWithEventDispatch_DougBlocksUnauthorizedEntry);
            }
            TalkClose();
        }
    }
}

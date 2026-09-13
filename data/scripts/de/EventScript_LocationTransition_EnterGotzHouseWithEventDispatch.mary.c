#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterGotzHouseWithEventDispatch_DoorIsLocked[] =
        "Abgeschlossen...{Press}";
};

void EventScript_LocationTransition_EnterGotzHouseWithEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_SEASON);
        var_2 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        var_4 = VarGet(VAR_DAY_OF_WEEK);
        var_5 = VarGet(VAR_WEATHER_TODAY);
        var_6 = VarGet(VAR_YEAR);
        if (GetEntityLocation(ENTITY_GOTZ) == MAP_GOTZ_HOUSE)
        {
            if (GetNpcFriendship(CHARACTER_GOTZ) <= 100)
            {
                if (var_3 >= 10 && var_3 < 19)
                {
                    var_0 = TRUE;
                }
            }
            else
            {
                if (GetNpcFriendship(CHARACTER_GOTZ) > 100)
                {
                    if (var_3 >= 8 && var_3 < 20)
                    {
                        var_0 = TRUE;
                    }
                    if (GetNpcFriendship(CHARACTER_GOTZ) > 200)
                    {
                        if (var_3 >= 6 && var_3 < 22)
                        {
                            var_0 = TRUE;
                        }
                    }
                }
            }
        }
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_GOTZ_HOUSE, X(120), Y(208));
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
            if (VarGet(VAR_GOTZ_LOSES_MOTIVATION_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_6 >= 3 && var_5 == WEATHER_SUNNY && var_1 == SEASON_SUMMER && (var_3 >= 13 && var_3 < 22) && GetNpcFriendship(CHARACTER_GOTZ) < 100 && HasMetNpc(CHARACTER_GOTZ) == TRUE && GetEntityLocation(ENTITY_GOTZ) == MAP_GOTZ_HOUSE)
            {
                VarSet(VAR_GOTZ_LOSES_MOTIVATION_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                CallScript(EventScript_NPCEvent_Gotz_LosesMotivation);
            }
            else
            {
                if (VarGet(VAR_GOTZ_LOSES_MOTIVATION_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_GOTZ_WORK_SUSPENDED) == TRUE && VarGet(VAR_GOTZ_REGAINS_MOTIVATION_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 != SEASON_SUMMER && var_5 == WEATHER_SUNNY && (var_3 >= 13 && var_3 < 22) && GetNpcFriendship(CHARACTER_GOTZ) >= 150 && GetEntityLocation(ENTITY_GOTZ) == MAP_GOTZ_HOUSE)
                {
                    VarSet(VAR_GOTZ_REGAINS_MOTIVATION_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_NPCEvent_Gotz_RegainsMotivation);
                }
                else
                {
                    if (VarGet(VAR_GOTZ_AND_HARRIS_PATROL_DISCUSSION_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_4 == DAY_OF_WEEK_SUNDAY && (var_3 >= 10 && var_3 < 13) && GetNpcFriendship(CHARACTER_GOTZ) >= 200 && HasMetNpc(CHARACTER_GOTZ) == TRUE && HasMetNpc(CHARACTER_HARRIS) == TRUE && GetEntityLocation(ENTITY_GOTZ) == MAP_GOTZ_HOUSE && GetEntityLocation(ENTITY_HARRIS) == MAP_GOTZ_HOUSE)
                    {
                        VarSet(VAR_GOTZ_AND_HARRIS_PATROL_DISCUSSION_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_NPCEvent_GotzAndHarris_PatrolDiscussion);
                    }
                }
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterGotzHouseWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}

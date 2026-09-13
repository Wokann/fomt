#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterAjaWinery1FWithEventDispatch_DoorIsLocked[] =
        "カギがかかっている…{Press}";
};

void EventScript_LocationTransition_EnterAjaWinery1FWithEventDispatch(void)
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
        if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30)
        {
            var_0 = FALSE;
        }
        else
        {
            if (VarGet(VAR_ANN_AND_CLIFF_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_ANN_CLIFF_WEDDING_MISSED) == TRUE)
            {
                var_0 = FALSE;
            }
            else
            {
                if (GetEntityLocation(ENTITY_MANNA) == MAP_AJA_WINERY_1F)
                {
                    if (GetNpcFriendship(CHARACTER_MANNA) <= 100)
                    {
                        if (var_3 >= 10 && var_3 < 19)
                        {
                            var_0 = TRUE;
                        }
                    }
                    else
                    {
                        if (GetNpcFriendship(CHARACTER_MANNA) > 100)
                        {
                            if (var_3 >= 8 && var_3 < 20)
                            {
                                var_0 = TRUE;
                            }
                            if (GetNpcFriendship(CHARACTER_MANNA) > 200)
                            {
                                if (var_3 >= 6 && var_3 < 22)
                                {
                                    var_0 = TRUE;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_AJA_WINERY_1F, X(120), Y(208));
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
            if (var_6 == 1 && VarGet(VAR_DUKE_GRAPE_HARVEST_INVITATION_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_CLIFF_PERMANENT_WINERY_JOB_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_15 && (var_3 >= 10 && var_3 < 15))
            {
                CallScript(EventScript_NPCEvent_Cliff_PermanentWineryJob);
            }
            else
            {
                if (VarGet(VAR_DUKE_AND_MANNA_MISSING_JUICE_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE && var_4 == DAY_OF_WEEK_SATURDAY && (var_3 >= 20 && var_3 < 22) && HasMetNpc(CHARACTER_DUKE) == TRUE && HasMetNpc(CHARACTER_MANNA) == TRUE && GetNpcFriendship(CHARACTER_DUKE) >= 100 && GetNpcFriendship(CHARACTER_MANNA) > 200)
                {
                    VarSet(VAR_DUKE_AND_MANNA_MISSING_JUICE_ARGUMENT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_NPCEvent_DukeAndManna_MissingJuiceArgument);
                }
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterAjaWinery1FWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}

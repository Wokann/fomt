#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ReturnToMothersHillWithRivalEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6;
    var_0 = VarGet(VAR_SEASON);
    var_1 = VarGet(VAR_DAY);
    var_3 = VarGet(VAR_HOUR);
    var_2 = VarGet(VAR_DAY_OF_WEEK);
    var_4 = VarGet(VAR_WEATHER_TODAY);
    var_5 = VarGet(VAR_YEAR);
    var_6 = GetEntityLocation(ENTITY_PLAYER);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (MAP_SPRING_MINE_FLOOR_0 <= var_6 && var_6 < MAP_SPRING_MINE_FLOOR_0 + 256)
    {
        ChangeMap(MAP_MOTHERS_HILL_MIDDLE, X(900), Y(350));
        SetEntityPosition(ENTITY_PLAYER, X(900), Y(350), FACING_DOWN);
        if (VarGet(VAR_RICK_KAREN_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30) && !(var_2 == DAY_OF_WEEK_SUNDAY || var_2 == DAY_OF_WEEK_MONDAY || var_2 == DAY_OF_WEEK_TUESDAY) && var_4 == WEATHER_SUNNY && (var_3 >= 11 && var_3 < 18) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetEntityLocation(ENTITY_POPURI) != MAP_MOTHERS_HILL_MIDDLE && GetEntityLocation(ENTITY_ANN) != MAP_MOTHERS_HILL_MIDDLE && GetEntityLocation(ENTITY_BARLEY) != MAP_MOTHERS_HILL_MIDDLE && GetEntityLocation(ENTITY_MAY) != MAP_MOTHERS_HILL_MIDDLE && GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_PURPLE_MIN && HasMetNpc(CHARACTER_KAREN) == TRUE && HasMetNpc(CHARACTER_RICK) == TRUE)
        {
            VarSet(VAR_RICK_KAREN_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            CallScript(EventScript_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion);
        }
        else
        {
            if (VarGet(VAR_RICK_KAREN_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_RICK_KAREN_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (!(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01) || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30) && var_5 >= 2 && var_4 == WEATHER_SUNNY && (var_2 == DAY_OF_WEEK_WEDNESDAY || var_2 == DAY_OF_WEEK_FRIDAY) && (var_3 >= 11 && var_3 < 18) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetEntityLocation(ENTITY_POPURI) != MAP_MOTHERS_HILL_MIDDLE && GetEntityLocation(ENTITY_ANN) != MAP_MOTHERS_HILL_MIDDLE && GetEntityLocation(ENTITY_BARLEY) != MAP_MOTHERS_HILL_MIDDLE && GetEntityLocation(ENTITY_MAY) != MAP_MOTHERS_HILL_MIDDLE && GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_YELLOW_MIN)
            {
                VarSet(VAR_RICK_KAREN_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                CallScript(EventScript_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue);
            }
        }
    }
    else
    {
        if (MAP_LAKE_MINE_FLOOR_0 <= var_6 && var_6 < MAP_LAKE_MINE_FLOOR_0 + 256)
        {
            ChangeMap(MAP_MOTHERS_HILL_MIDDLE, X(424), Y(448));
            SetEntityPosition(ENTITY_PLAYER, X(424), Y(448), FACING_DOWN);
        }
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
}

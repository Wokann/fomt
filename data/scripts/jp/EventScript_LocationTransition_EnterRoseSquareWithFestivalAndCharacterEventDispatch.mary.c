#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterRoseSquareWithFestivalAndCharacterEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_ROSE_SQUARE, X(220), Y(432));
        SetEntityPosition(ENTITY_PLAYER, X(220), Y(432), FACING_UP);
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_2 = VarGet(VAR_HOUR);
        var_3 = VarGet(VAR_YEAR);
        var_4 = VarGet(VAR_WEATHER_TODAY);
        var_5 = VarGet(VAR_DAY_OF_WEEK);
        if (VarGet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01)
        {
            if (var_2 >= 6 && var_2 < 18)
            {
                CallScript(EventScript_FestivalEvent_DayAnnouncement_SouthTownEntrance);
            }
            else
            {
                if (var_2 >= 18)
                {
                    VarSet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_FestivalEvent_NewYearsDayRiceCakeFestival_Opening);
                }
            }
        }
        else
        {
            if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18)
            {
                if (var_2 >= 6 && var_2 < 10)
                {
                    CallScript(EventScript_FestivalEvent_DayAnnouncement_SouthTownEntrance);
                }
                else
                {
                    if (var_2 >= 10 && var_2 < 18)
                    {
                        VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
                        CallScript(EventScript_FestivalEvent_SpringHorseRace_Opening);
                    }
                }
            }
            else
            {
                if (var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22)
                {
                    if (VarGet(VAR_COOKING_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE)
                    {
                        if (var_2 >= 6 && var_2 < 10)
                        {
                            CallScript(EventScript_FestivalEvent_DayAnnouncement_SouthTownEntrance);
                        }
                        else
                        {
                            if (var_2 >= 10 && var_2 < 12)
                            {
                                VarSet(VAR_COOKING_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
                                CallScript(EventScript_FestivalEvent_CookingFestival_Opening);
                            }
                        }
                    }
                    if (VarGet(VAR_COOKING_FESTIVAL_COMPLETED) == FESTIVAL_PHASE_INACTIVE)
                    {
                        if (var_2 >= 12 && var_2 < 18)
                        {
                            if (VarGet(VAR_COOKING_FESTIVAL_ACTIVE) != FESTIVAL_PHASE_ADVANCED)
                            {
                                if (VarGet(VAR_YEAR) <= 5)
                                {
                                    var_6 = VarGet(VAR_YEAR);
                                }
                                switch (var_6)
                                {
                                    case 1:
                                        VarSet(VAR_COOKING_FESTIVAL_DISH_CATEGORY, FESTIVAL_COOKING_DISH_CATEGORY_JUICE);
                                        break;
                                    case 2:
                                        VarSet(VAR_COOKING_FESTIVAL_DISH_CATEGORY, FESTIVAL_COOKING_DISH_CATEGORY_DESSERT);
                                        break;
                                    case 3:
                                        VarSet(VAR_COOKING_FESTIVAL_DISH_CATEGORY, FESTIVAL_COOKING_DISH_CATEGORY_BREAD);
                                        break;
                                    case 4:
                                        VarSet(VAR_COOKING_FESTIVAL_DISH_CATEGORY, FESTIVAL_COOKING_DISH_CATEGORY_NOODLES);
                                        break;
                                    case 5:
                                        VarSet(VAR_COOKING_FESTIVAL_DISH_CATEGORY, FESTIVAL_COOKING_DISH_CATEGORY_RICE);
                                        break;
                                }
                            }
                            VarSet(VAR_COOKING_FESTIVAL_COMPLETED, FESTIVAL_PHASE_INITIAL);
                            CallScript(EventScript_FestivalEvent_CookingFestival_JudgingSceneSetup);
                        }
                    }
                }
                else
                {
                    if (VarGet(VAR_CHICKEN_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07)
                    {
                        if (var_2 >= 6 && var_2 < 10)
                        {
                            CallScript(EventScript_FestivalEvent_DayAnnouncement_SouthTownEntrance);
                        }
                        else
                        {
                            if (var_2 >= 10 && var_2 < 18)
                            {
                                VarSet(VAR_CHICKEN_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
                                CallScript(EventScript_FestivalEvent_ChickenFestival_OpeningScene);
                            }
                        }
                    }
                    else
                    {
                        if (VarGet(VAR_COW_FESTIVAL_SESSION_STATE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20)
                        {
                            if (var_2 >= 6 && var_2 < 10)
                            {
                                CallScript(EventScript_FestivalEvent_DayAnnouncement_SouthTownEntrance);
                            }
                            else
                            {
                                if (var_2 >= 10 && var_2 < 18)
                                {
                                    VarSet(VAR_COW_FESTIVAL_SESSION_STATE, FESTIVAL_PHASE_INITIAL);
                                    CallScript(EventScript_FestivalEvent_CowFestival_Opening);
                                }
                            }
                        }
                        else
                        {
                            if (VarGet(VAR_HARVEST_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09)
                            {
                                if (var_2 >= 6 && var_2 < 10)
                                {
                                    CallScript(EventScript_FestivalEvent_DayAnnouncement_SouthTownEntrance);
                                }
                                else
                                {
                                    if (var_2 >= 10 && var_2 < 18)
                                    {
                                        VarSet(VAR_HARVEST_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
                                        CallScript(EventScript_FestivalEvent_HarvestFestival_IngredientContributionSceneSetup);
                                    }
                                }
                            }
                            else
                            {
                                if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18)
                                {
                                    if (var_2 >= 6 && var_2 < 10)
                                    {
                                        CallScript(EventScript_FestivalEvent_DayAnnouncement_SouthTownEntrance);
                                    }
                                    else
                                    {
                                        if (var_2 >= 10 && var_2 < 18)
                                        {
                                            VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
                                            CallScript(EventScript_FestivalEvent_FallHorseRace_Opening);
                                        }
                                    }
                                }
                                else
                                {
                                    if (VarGet(VAR_SHEEP_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21)
                                    {
                                        if (var_2 >= 6 && var_2 < 10)
                                        {
                                            CallScript(EventScript_FestivalEvent_DayAnnouncement_SouthTownEntrance);
                                        }
                                        else
                                        {
                                            if (var_2 >= 10 && var_2 < 18)
                                            {
                                                VarSet(VAR_SHEEP_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
                                                CallScript(EventScript_FestivalEvent_SheepFestival_Opening);
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_NEW_YEARS_EVE_NOODLE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30)
                                        {
                                            if (var_2 >= 6 && var_2 < 18)
                                            {
                                                CallScript(EventScript_FestivalEvent_DayAnnouncement_SouthTownEntrance);
                                            }
                                            else
                                            {
                                                if (var_2 >= 18)
                                                {
                                                    VarSet(VAR_NEW_YEARS_EVE_NOODLE_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                    CallScript(EventScript_FestivalEvent_NewYearsEve_NoodleFestivalOpening);
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_CLIFF_COLLAPSES_IN_SNOW_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_3 == 1 && var_4 == WEATHER_SNOW && var_0 == SEASON_WINTER && (var_1 >= DAY_OF_MONTH_01 && var_1 <= DAY_OF_MONTH_26) && (var_2 >= 10 && var_2 < 15) && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && GetNpcFriendship(CHARACTER_CLIFF) >= 50 && HasMetNpc(CHARACTER_CLIFF) == TRUE && IsPlayerHoldingNothing() == TRUE)
                                            {
                                                VarSet(VAR_CLIFF_COLLAPSES_IN_SNOW_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                CallScript(EventScript_NPCEvent_Cliff_CollapsesInSnow);
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_MANNA_AJAS_DEPARTURE_ADVICE_FROM_FRIENDS_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE && var_4 == WEATHER_SUNNY && var_5 != DAY_OF_WEEK_TUESDAY && (var_2 >= 13 && var_2 < 16) && GetNpcFriendship(CHARACTER_SASHA) >= 100 && GetEntityLocation(ENTITY_SASHA) == MAP_ROSE_SQUARE && GetEntityLocation(ENTITY_MANNA) == MAP_ROSE_SQUARE && GetEntityLocation(ENTITY_ANNA) == MAP_ROSE_SQUARE)
                                                {
                                                    VarSet(VAR_MANNA_AJAS_DEPARTURE_ADVICE_FROM_FRIENDS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                    CallScript(EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends);
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
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

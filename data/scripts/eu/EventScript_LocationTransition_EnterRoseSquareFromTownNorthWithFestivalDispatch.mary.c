#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterRoseSquareFromTownNorthWithFestivalDispatch(void)
{
    int var_0, var_1, var_2, var_3;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_ROSE_SQUARE, X(220), Y(24));
        SetEntityPosition(ENTITY_PLAYER, X(220), Y(24), FACING_DOWN);
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_2 = VarGet(VAR_HOUR);
        if (VarGet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01)
        {
            if (var_2 >= 6 && var_2 < 18)
            {
                CallScript(EventScript_FestivalEvent_DayAnnouncement_NorthTownEntrance);
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
                    CallScript(EventScript_FestivalEvent_DayAnnouncement_NorthTownEntrance);
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
                            CallScript(EventScript_FestivalEvent_DayAnnouncement_NorthTownEntrance);
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
                                    var_3 = VarGet(VAR_YEAR);
                                }
                                switch (var_3)
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
                            CallScript(EventScript_FestivalEvent_DayAnnouncement_NorthTownEntrance);
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
                                CallScript(EventScript_FestivalEvent_DayAnnouncement_NorthTownEntrance);
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
                                    CallScript(EventScript_FestivalEvent_DayAnnouncement_NorthTownEntrance);
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
                                        CallScript(EventScript_FestivalEvent_DayAnnouncement_NorthTownEntrance);
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
                                            CallScript(EventScript_FestivalEvent_DayAnnouncement_NorthTownEntrance);
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
                                                CallScript(EventScript_FestivalEvent_DayAnnouncement_NorthTownEntrance);
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

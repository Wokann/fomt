#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterRoseSquareFromBeachWithFestivalDispatch_WhereAreYouGoingTheFireworks[] =
        "Where are you going?\r\n"
        "The fireworks are\r\n"
        "about to start!{Press}";

    const char gText_LocationTransition_EnterRoseSquareFromBeachWithFestivalDispatch_ZackBlocksExitBeforeBeachDayFestival[] =
        "Where are you going?\r\n"
        "The Beach Day\r\n"
        "is about to start!{Press}";

    const char gText_LocationTransition_EnterRoseSquareFromBeachWithFestivalDispatch_BeachDayFestivalConcludesAndReturnsPlayerToWork[] =
        "That was fun!\r\n"
        "Alright, back to work...{Press}";
};

void EventScript_LocationTransition_EnterRoseSquareFromBeachWithFestivalDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
    mary_nodisc(var_5 = 1);
    var_0 = VarGet(VAR_SEASON);
    var_1 = VarGet(VAR_DAY);
    var_2 = VarGet(VAR_HOUR);
    var_3 = VarGet(VAR_MINUTE);
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_LEFT)
    {
        if (VarGet(VAR_FIREWORKS_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_LocationTransition_EnterRoseSquareFromBeachWithFestivalDispatch_WhereAreYouGoingTheFireworks);
            TalkClose();
            var_5 = 0;
        }
        else
        {
            if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                VarSet(VAR_POPURI_KAI_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                ClearEntityEventScript(ENTITY_POPURI);
                ClearEntityEventScript(ENTITY_KAI);
                DisableScriptedNpcControl();
            }
            else
            {
                if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    VarSet(VAR_POPURI_KAI_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                    ClearEntityEventScript(ENTITY_KAI);
                    DisableScriptedNpcControl();
                }
                else
                {
                    if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        VarSet(VAR_POPURI_KAI_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_COMPLETED);
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_KAI);
                        DisableScriptedNpcControl();
                    }
                    else
                    {
                        if (VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                        {
                            VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_COMPLETED);
                            ClearEntityEventScript(ENTITY_DOCTOR);
                            ClearEntityEventScript(ENTITY_ELLI);
                            DisableScriptedNpcControl();
                        }
                        else
                        {
                            if (VarGet(VAR_BEACH_DAY_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                            {
                                if (!(var_2 == 18 && var_3 == 1))
                                {
                                    TalkOpen();
                                    SetTalkPortrait(TALK_PORTRAIT_ZACK_ANGRY);
                                    SetTalkNameplateCharacter(CHARACTER_ZACK);
                                    TalkMessage(gText_LocationTransition_EnterRoseSquareFromBeachWithFestivalDispatch_ZackBlocksExitBeforeBeachDayFestival);
                                    TalkClose();
                                    var_5 = 0;
                                }
                                else
                                {
                                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                    if (VarGet(VAR_FRISBEE_TOURNAMENT_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
                                    {
                                        AddNpcFriendship(CHARACTER_THOMAS, 20);
                                        AddNpcFriendship(CHARACTER_JEFF, 20);
                                        AddNpcFriendship(CHARACTER_SASHA, 20);
                                        AddNpcFriendship(CHARACTER_KAI, 20);
                                        AddNpcFriendship(CHARACTER_POPURI, 20);
                                        AddNpcFriendship(CHARACTER_ZACK, 20);
                                    }
                                    TalkOpen();
                                    TalkMessage(gText_LocationTransition_EnterRoseSquareFromBeachWithFestivalDispatch_BeachDayFestivalConcludesAndReturnsPlayerToWork);
                                    TalkClose();
                                    DisableScriptedNpcControl();
                                    VarSet(VAR_BEACH_DAY_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                                    ClearContestAnimal(ANIMAL_KIND_DOG);
                                    VarSet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED, FALSE);
                                    ClearEntityEventScript(ENTITY_THOMAS);
                                    ClearEntityEventScript(ENTITY_JEFF);
                                    ClearEntityEventScript(ENTITY_SASHA);
                                    ClearEntityEventScript(ENTITY_KAI);
                                    ClearEntityEventScript(ENTITY_POPURI);
                                    ClearEntityEventScript(ENTITY_ZACK);
                                    PlacePlayerAtFarmhouseBed();
                                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                                    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (var_5)
        {
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_ROSE_SQUARE, X(456), Y(128));
            SetEntityPosition(ENTITY_PLAYER, X(456), Y(128), FACING_LEFT);
            var_0 = VarGet(VAR_SEASON);
            var_1 = VarGet(VAR_DAY);
            var_2 = VarGet(VAR_HOUR);
            if (VarGet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01)
            {
                if (var_2 >= 6 && var_2 < 18)
                {
                    CallScript(EventScript_FestivalEvent_DayAnnouncement_BeachEntrance);
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
                        CallScript(EventScript_FestivalEvent_DayAnnouncement_BeachEntrance);
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
                                CallScript(EventScript_FestivalEvent_DayAnnouncement_BeachEntrance);
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
                                        var_4 = VarGet(VAR_YEAR);
                                    }
                                    switch (var_4)
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
                                CallScript(EventScript_FestivalEvent_DayAnnouncement_BeachEntrance);
                                return;
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
                                    CallScript(EventScript_FestivalEvent_DayAnnouncement_BeachEntrance);
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
                                        CallScript(EventScript_FestivalEvent_DayAnnouncement_BeachEntrance);
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
                                            CallScript(EventScript_FestivalEvent_DayAnnouncement_BeachEntrance);
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
                                                CallScript(EventScript_FestivalEvent_DayAnnouncement_BeachEntrance);
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
                                                    CallScript(EventScript_FestivalEvent_DayAnnouncement_BeachEntrance);
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
        else
        {
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            MoveEntityXTo(ENTITY_PLAYER, X(56), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
        }
    }
}

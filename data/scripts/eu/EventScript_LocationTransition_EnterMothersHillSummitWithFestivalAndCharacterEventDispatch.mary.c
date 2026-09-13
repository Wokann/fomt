#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterMothersHillSummitWithFestivalAndCharacterEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        if (VarGet(VAR_DOCTOR_REFLECTS_ON_PARENTS_AND_MEDICAL_CALLING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            DisableScriptedNpcControl();
            ClearEntityEventScript(ENTITY_DOCTOR);
            AddNpcFriendship(CHARACTER_DOCTOR, 20);
            VarSet(VAR_DOCTOR_REFLECTS_ON_PARENTS_AND_MEDICAL_CALLING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        ChangeMap(MAP_MOTHERS_HILL_SUMMIT, X(236), Y(464));
        SetEntityPosition(ENTITY_PLAYER, X(236), Y(464), FACING_UP);
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        var_2 = VarGet(VAR_DAY_OF_WEEK);
        var_4 = VarGet(VAR_WEATHER_TODAY);
        var_5 = VarGet(VAR_YEAR);
        if (VarGet(VAR_MOON_VIEWING_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13)
        {
            if (var_3 >= 18)
            {
                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && ((VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && (VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && (VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && (VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))))
                {
                    if (VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_GREEN_MIN || VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_GREEN_MIN || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) || (VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_GREEN_MIN || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) || (VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_GREEN_MIN || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) || (VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_GREEN_MIN || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        VarSet(VAR_MOON_VIEWING_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_FestivalEvent_MoonViewing_Opening);
                    }
                }
            }
        }
        else
        {
            if (VarGet(VAR_NEW_YEAR_SUNRISE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01)
            {
                if (var_3 >= 0 && var_3 < 6)
                {
                    VarSet(VAR_NEW_YEAR_SUNRISE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_FestivalEvent_NewYearSunrise_Opening);
                }
            }
            else
            {
                if (VarGet(VAR_MARY_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_MARY_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30) && var_2 == DAY_OF_WEEK_MONDAY && var_4 == WEATHER_SUNNY && (var_3 >= 12 && var_3 < 17) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetEntityLocation(ENTITY_DOUG) != MAP_MOTHERS_HILL_SUMMIT && GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_BLUE_MIN && IsPlayerHoldingNothing() == TRUE && (VarGet(VAR_RUCKSACK_UPGRADE_LEVEL) == RUCKSACK_UPGRADE_LARGE || VarGet(VAR_HAS_SHELF) == TRUE))
                {
                    VarSet(VAR_MARY_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_LoveEvent_Mary_03_BlueHeart_DiscussEmotionalNovel);
                }
                else
                {
                    if (VarGet(VAR_MARY_GRAY_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_MARY_GRAY_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30) && (var_2 == DAY_OF_WEEK_SUNDAY || var_2 == DAY_OF_WEEK_TUESDAY || var_2 == DAY_OF_WEEK_FRIDAY) && var_5 >= 2 && var_4 == WEATHER_SUNNY && (var_3 >= 7 && var_3 < 10) && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_MARY) < LOVE_HEART_YELLOW_MIN && GetEntityLocation(ENTITY_DOUG) != MAP_MOTHERS_HILL_SUMMIT)
                    {
                        VarSet(VAR_MARY_GRAY_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement);
                    }
                    else
                    {
                        if (VarGet(VAR_ANN_MOTHERS_DEATH_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_05) && (var_3 >= 6 && var_3 < 17) && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && HasMetNpc(CHARACTER_DOUG) == TRUE)
                        {
                            VarSet(VAR_ANN_MOTHERS_DEATH_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_FamilyEvent_Ann_MothersDeathAnniversary);
                        }
                        else
                        {
                            if (VarGet(VAR_MARY_AND_GRAY_BOOK_AND_HEALTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30) && var_2 == DAY_OF_WEEK_THURSDAY && var_4 == WEATHER_SUNNY && (var_3 >= 13 && var_3 < 16) && (VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && GetEntityLocation(ENTITY_MARY) == MAP_MOTHERS_HILL_SUMMIT && GetEntityLocation(ENTITY_GRAY) == MAP_MOTHERS_HILL_SUMMIT && GetEntityLocation(ENTITY_DOUG) != MAP_MOTHERS_HILL_SUMMIT)
                            {
                                VarSet(VAR_MARY_AND_GRAY_BOOK_AND_HEALTH_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern);
                            }
                            else
                            {
                                if (VarGet(VAR_ELLEN_WHITE_FLOWER_LEGEND_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLEN_WHITE_FLOWER_DISCOVERY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30) && var_0 == SEASON_SUMMER && var_4 == WEATHER_SUNNY && (var_3 >= 21 && var_3 <= 23))
                                {
                                    VarSet(VAR_ELLEN_WHITE_FLOWER_DISCOVERY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                    CallScript(EventScript_NPCEvent_Ellen_WhiteFlowerDiscovery);
                                }
                                else
                                {
                                    if (var_5 >= 5 && var_4 == WEATHER_SUNNY && (var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_10 && (var_3 >= 18 && var_3 <= 23) || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_11 && (var_3 >= 0 && var_3 < 6)))
                                    {
                                        switch (VarGet(VAR_YEAR) % 5)
                                        {
                                            case 0:
                                                CallScript(EventScript_FestivalEvent_ShootingStar_WishChoice);
                                                break;
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

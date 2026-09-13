#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterPoultryFarmHouse1FWithEventDispatch_DoorIsLocked[] =
        "Abgeschlossen...{Press}";
};

void EventScript_LocationTransition_EnterPoultryFarmHouse1FWithEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_SEASON);
        var_2 = VarGet(VAR_DAY);
        var_4 = VarGet(VAR_HOUR);
        var_3 = VarGet(VAR_DAY_OF_WEEK);
        var_5 = VarGet(VAR_WEATHER_TODAY);
        var_6 = VarGet(VAR_YEAR);
        if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30)
        {
            var_0 = FALSE;
        }
        else
        {
            if (VarGet(VAR_RICK_AND_POPURI_SICK_LILLIA_FOLLOWUP_STATE) == TRUE)
            {
                var_0 = FALSE;
            }
            else
            {
                if (var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24)
                {
                    if (VarGet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX) == STARRY_NIGHT_HOST_POPURI_HOUSEHOLD)
                    {
                        if (var_4 >= 18)
                        {
                            var_0 = TRUE;
                        }
                    }
                    else
                    {
                        var_0 = FALSE;
                    }
                }
                else
                {
                    if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        if (GetEntityLocation(ENTITY_LILLIA) == MAP_POULTRY_FARM_HOUSE_1F)
                        {
                            if (GetNpcFriendship(CHARACTER_LILLIA) <= 100)
                            {
                                if (var_4 >= 11 && var_4 < 19)
                                {
                                    var_0 = TRUE;
                                }
                            }
                            else
                            {
                                if (GetNpcFriendship(CHARACTER_LILLIA) > 100)
                                {
                                    if (var_4 >= 8 && var_4 < 20)
                                    {
                                        var_0 = TRUE;
                                    }
                                    if (GetNpcFriendship(CHARACTER_LILLIA) > 200)
                                    {
                                        if (var_4 >= 6 && var_4 < 22)
                                        {
                                            var_0 = TRUE;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if (VarGet(VAR_POPURI_AND_KAI_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_POPURI_KAI_WEDDING_MISSED) == TRUE || (VarGet(VAR_RICK_AND_KAREN_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_RICK_KAREN_WEDDING_MISSED) == TRUE))
                        {
                            var_0 = FALSE;
                        }
                        else
                        {
                            if (VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_SUNDAY)
                            {
                                if (GetEntityLocation(ENTITY_RICK) == MAP_POULTRY_FARM_HOUSE_1F)
                                {
                                    if (GetNpcFriendship(CHARACTER_RICK) <= 100)
                                    {
                                        if (var_4 >= 11 && var_4 < 19)
                                        {
                                            var_0 = TRUE;
                                        }
                                    }
                                    else
                                    {
                                        if (GetNpcFriendship(CHARACTER_RICK) > 100)
                                        {
                                            if (var_4 >= 8 && var_4 < 20)
                                            {
                                                var_0 = TRUE;
                                            }
                                            if (GetNpcFriendship(CHARACTER_RICK) > 200)
                                            {
                                                if (var_4 >= 6 && var_4 < 22)
                                                {
                                                    var_0 = TRUE;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (GetEntityLocation(ENTITY_POPURI) == MAP_POULTRY_FARM_HOUSE_1F)
                                {
                                    if (GetNpcFriendship(CHARACTER_POPURI) <= 100)
                                    {
                                        if (var_4 >= 11 && var_4 < 19)
                                        {
                                            var_0 = TRUE;
                                        }
                                    }
                                    else
                                    {
                                        if (GetNpcFriendship(CHARACTER_POPURI) > 100)
                                        {
                                            if (var_4 >= 8 && var_4 < 20)
                                            {
                                                var_0 = TRUE;
                                            }
                                            if (GetNpcFriendship(CHARACTER_POPURI) > 200)
                                            {
                                                if (var_4 >= 6 && var_4 < 22)
                                                {
                                                    var_0 = TRUE;
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
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_POULTRY_FARM_HOUSE_1F, X(120), Y(208));
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
            if (var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 && VarGet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX) == STARRY_NIGHT_HOST_POPURI_HOUSEHOLD)
            {
                if (var_4 >= 18)
                {
                    CallScript(EventScript_FestivalEvent_StarryNight_WithPopuriFamily);
                }
            }
            else
            {
                if (VarGet(VAR_POPURI_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_1 == SEASON_SUMMER) && !(var_3 == DAY_OF_WEEK_SUNDAY || var_3 == DAY_OF_WEEK_TUESDAY) && var_5 == WEATHER_SUNNY && (var_4 >= 10 && var_4 < 13) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_YELLOW_MIN && GetEntityLocation(ENTITY_LILLIA) == MAP_POULTRY_FARM_HOUSE_1F && GetEntityLocation(ENTITY_RICK) == MAP_POULTRY_FARM_HOUSE_1F && GetEntityLocation(ENTITY_POPURI) == MAP_POULTRY_FARM_HOUSE_1F && IsPlayerHoldingNothing() == TRUE)
                {
                    VarSet(VAR_POPURI_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument);
                }
                else
                {
                    if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_6 >= 4 && var_1 == SEASON_SUMMER && (var_3 == DAY_OF_WEEK_TUESDAY || var_3 == DAY_OF_WEEK_THURSDAY || var_3 == DAY_OF_WEEK_SATURDAY) && var_5 == WEATHER_SUNNY && (var_4 >= 9 && var_4 < 19) && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_RED_MIN && GetEntityLocation(ENTITY_LILLIA) == MAP_POULTRY_FARM_HOUSE_1F && GetEntityLocation(ENTITY_RICK) == MAP_POULTRY_FARM_HOUSE_1F && GetEntityLocation(ENTITY_POPURI) == MAP_POULTRY_FARM_HOUSE_1F)
                    {
                        VarSet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval);
                    }
                    else
                    {
                        if (VarGet(VAR_RICK_AND_POPURI_RUSH_TO_SICK_LILLIA_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_SUMMER && (var_4 >= 10 && var_4 < 13) && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && GetNpcFriendship(CHARACTER_LILLIA) >= 100 && GetEntityLocation(ENTITY_LILLIA) == MAP_POULTRY_FARM_HOUSE_1F && GetEntityLocation(ENTITY_RICK) == MAP_POULTRY_FARM_HOUSE_1F && GetEntityLocation(ENTITY_POPURI) == MAP_POULTRY_FARM_HOUSE_1F && HasMetNpc(CHARACTER_LILLIA) == TRUE)
                        {
                            VarSet(VAR_RICK_AND_POPURI_RUSH_TO_SICK_LILLIA_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_NPCEvent_RickAndPopuri_RushToSickLillia);
                        }
                        else
                        {
                            if (VarGet(VAR_LILLIA_READS_RODS_LETTER_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_6 >= 3 && var_1 == SEASON_SUMMER && !(var_3 == DAY_OF_WEEK_SUNDAY || var_3 == DAY_OF_WEEK_TUESDAY) && (var_4 >= 10 && var_4 < 13) && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && GetNpcFriendship(CHARACTER_LILLIA) >= 200 && GetEntityLocation(ENTITY_LILLIA) == MAP_POULTRY_FARM_HOUSE_1F && GetEntityLocation(ENTITY_RICK) == MAP_POULTRY_FARM_HOUSE_1F && GetEntityLocation(ENTITY_POPURI) == MAP_POULTRY_FARM_HOUSE_1F && HasMetNpc(CHARACTER_LILLIA) == TRUE)
                            {
                                VarSet(VAR_LILLIA_READS_RODS_LETTER_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_NPCEvent_Lillia_ReadsRodsLetter);
                            }
                            else
                            {
                                if (VarGet(VAR_KAREN_COMFORTS_LONELY_RICK_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 != SEASON_SUMMER && (var_4 >= 16 && var_4 < 19) && (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && (VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && GetEntityLocation(ENTITY_RICK) == MAP_POULTRY_FARM_HOUSE_1F && GetEntityLocation(ENTITY_KAREN) == MAP_POULTRY_FARM_HOUSE_1F)
                                {
                                    VarSet(VAR_KAREN_COMFORTS_LONELY_RICK_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                    CallScript(EventScript_NPCEvent_Karen_ComfortsLonelyRick);
                                }
                                else
                                {
                                    if (VarGet(VAR_ZACK_VISITS_SICK_LILLIA_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_6 >= 4 && var_5 == WEATHER_SUNNY && var_1 == SEASON_SUMMER && var_3 == DAY_OF_WEEK_SUNDAY && (var_4 >= 11 && var_4 < 13) && HasMetNpc(CHARACTER_ZACK) == TRUE)
                                    {
                                        VarSet(VAR_ZACK_VISITS_SICK_LILLIA_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                        CallScript(EventScript_NPCEvent_Zack_VisitsSickLillia);
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_3 == DAY_OF_WEEK_TUESDAY && (var_4 >= 10 && var_4 < 13) && GetNpcFriendship(CHARACTER_SASHA) >= 170 && GetEntityLocation(ENTITY_SASHA) == MAP_POULTRY_FARM_HOUSE_1F && HasMetNpc(CHARACTER_LILLIA) == TRUE && HasMetNpc(CHARACTER_SASHA) == TRUE)
                                        {
                                            VarSet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                            CallScript(EventScript_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage);
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
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterPoultryFarmHouse1FWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}

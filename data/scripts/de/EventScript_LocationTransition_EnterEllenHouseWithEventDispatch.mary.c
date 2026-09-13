#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterEllenHouseWithEventDispatch_DoorIsLocked[] =
        "Abgeschlossen...{Press}";
};

void EventScript_LocationTransition_EnterEllenHouseWithEventDispatch(void)
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
        if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30)
        {
            var_0 = FALSE;
        }
        else
        {
            if (var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24)
            {
                if (VarGet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX) == STARRY_NIGHT_HOST_ELLI_HOUSEHOLD)
                {
                    if (var_3 >= 18)
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
                if (VarGet(VAR_ELLI_AND_DOCTOR_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_ELLI_DOCTOR_WEDDING_MISSED) == TRUE)
                {
                    var_0 = FALSE;
                }
                else
                {
                    if (GetEntityLocation(ENTITY_ELLEN) == MAP_ELLEN_HOUSE)
                    {
                        if (GetNpcFriendship(CHARACTER_ELLEN) <= 100)
                        {
                            if (var_3 >= 10 && var_3 < 19)
                            {
                                var_0 = TRUE;
                            }
                        }
                        else
                        {
                            if (GetNpcFriendship(CHARACTER_ELLEN) > 100)
                            {
                                if (var_3 >= 8 && var_3 < 20)
                                {
                                    var_0 = TRUE;
                                }
                                if (GetNpcFriendship(CHARACTER_ELLEN) > 200)
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
        }
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_ELLEN_HOUSE, X(120), Y(208));
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
            if (var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 && VarGet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX) == STARRY_NIGHT_HOST_ELLI_HOUSEHOLD)
            {
                if (var_3 >= 18)
                {
                    CallScript(EventScript_FestivalEvent_StarryNight_WithElliFamily);
                }
            }
            else
            {
                if (VarGet(VAR_ELLI_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLI_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_4 == DAY_OF_WEEK_WEDNESDAY && var_5 == WEATHER_SUNNY && (var_3 >= 9 && var_3 < 13) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_BLUE_MIN && GetEntityLocation(ENTITY_ELLI) == MAP_ELLEN_HOUSE && GetEntityLocation(ENTITY_STU) == MAP_ELLEN_HOUSE && IsPlayerHoldingNothing() == TRUE && (VarGet(VAR_RUCKSACK_UPGRADE_LEVEL) == RUCKSACK_UPGRADE_LARGE || VarGet(VAR_HAS_SHELF) == TRUE))
                {
                    VarSet(VAR_ELLI_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers);
                }
                else
                {
                    if (VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_4 == DAY_OF_WEEK_MONDAY && var_5 == WEATHER_SUNNY && (var_3 >= 9 && var_3 < 19) && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_GREEN_MIN)
                    {
                        VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall);
                    }
                    else
                    {
                        if (VarGet(VAR_ELLI_TREATS_STUS_COLD_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_4 == DAY_OF_WEEK_WEDNESDAY && (var_3 >= 9 && var_3 < 13) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && HasMetNpc(CHARACTER_STU) == TRUE && HasMetNpc(CHARACTER_ELLI) == TRUE && HasMetNpc(CHARACTER_ELLEN) == TRUE && GetEntityLocation(ENTITY_ELLI) == MAP_ELLEN_HOUSE)
                        {
                            VarSet(VAR_ELLI_TREATS_STUS_COLD_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_NPCEvent_ElliAndStu_StuColdClinicVisit);
                        }
                        else
                        {
                            if (VarGet(VAR_ELLEN_GRANDFATHERS_HIDDEN_LETTER_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_SUMMER && var_4 == DAY_OF_WEEK_WEDNESDAY && var_5 == WEATHER_SUNNY && (var_3 >= 9 && var_3 < 13) && GetNpcFriendship(CHARACTER_ELLEN) >= 100 && HasMetNpc(CHARACTER_STU) == TRUE && HasMetNpc(CHARACTER_ELLI) == TRUE && HasMetNpc(CHARACTER_ELLEN) == TRUE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && GetEntityLocation(ENTITY_ELLI) == MAP_ELLEN_HOUSE)
                            {
                                VarSet(VAR_ELLEN_GRANDFATHERS_HIDDEN_LETTER_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery);
                            }
                            else
                            {
                                if (VarGet(VAR_ELLI_AND_STU_PLAY_TOGETHER_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_4 == DAY_OF_WEEK_WEDNESDAY && (var_3 >= 10 && var_3 < 17) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && HasMetNpc(CHARACTER_STU) == TRUE && HasMetNpc(CHARACTER_ELLI) == TRUE && HasMetNpc(CHARACTER_ELLEN) == TRUE && GetEntityLocation(ENTITY_ELLI) == MAP_ELLEN_HOUSE)
                                {
                                    VarSet(VAR_ELLI_AND_STU_PLAY_TOGETHER_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                    CallScript(EventScript_NPCEvent_ElliAndStu_PlayTogetherChoice);
                                }
                                else
                                {
                                    if (VarGet(VAR_SAIBARA_VISITS_ELLEN_EVENT_1_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_6 >= 2 && var_1 != SEASON_WINTER && var_5 == WEATHER_RAIN && var_4 == DAY_OF_WEEK_FRIDAY && (var_3 >= 8 && var_3 < 17) && GetNpcFriendship(CHARACTER_ELLEN) >= 100 && GetNpcFriendship(CHARACTER_SAIBARA) >= 100 && HasMetNpc(CHARACTER_STU) == TRUE && HasMetNpc(CHARACTER_SAIBARA) == TRUE && HasMetNpc(CHARACTER_ELLEN) == TRUE && GetEntityLocation(ENTITY_STU) == MAP_ELLEN_HOUSE)
                                    {
                                        VarSet(VAR_SAIBARA_VISITS_ELLEN_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                        CallScript(EventScript_NPCEvent_Saibara_VisitsEllenFirstVisit);
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_SAIBARA_VISITS_ELLEN_EVENT_1_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_SAIBARA_VISITS_ELLEN_EVENT_2_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_6 >= 4 && var_4 == DAY_OF_WEEK_MONDAY && (var_3 >= 8 && var_3 < 17) && GetNpcFriendship(CHARACTER_ELLEN) >= 200 && GetNpcFriendship(CHARACTER_SAIBARA) >= 200 && GetEntityLocation(ENTITY_STU) == MAP_ELLEN_HOUSE)
                                        {
                                            VarSet(VAR_SAIBARA_VISITS_ELLEN_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                            CallScript(EventScript_NPCEvent_Saibara_VisitsEllenSecondVisit);
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_ELLEN_WHITE_FLOWER_LEGEND_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_6 >= 5 && var_1 == SEASON_SUMMER && (var_4 == DAY_OF_WEEK_THURSDAY || var_4 == DAY_OF_WEEK_FRIDAY || var_4 == DAY_OF_WEEK_SATURDAY) && var_5 == WEATHER_SUNNY && (var_3 >= 13 && var_3 < 16) && GetEntityLocation(ENTITY_THOMAS) != MAP_ELLEN_HOUSE && HasMetNpc(CHARACTER_BASIL) == TRUE && HasMetNpc(CHARACTER_ELLEN) == TRUE)
                                            {
                                                VarSet(VAR_ELLEN_WHITE_FLOWER_LEGEND_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                CallScript(EventScript_NPCEvent_Ellen_WhiteFlowerLegend);
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
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterEllenHouseWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}

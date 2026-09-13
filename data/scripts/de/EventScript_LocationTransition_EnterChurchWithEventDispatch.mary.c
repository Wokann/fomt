#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterChurchWithEventDispatch_DoorIsLocked[] =
        "Abgeschlossen...{Press}";
};

void EventScript_LocationTransition_EnterChurchWithEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_SEASON);
        var_2 = VarGet(VAR_DAY);
        var_4 = VarGet(VAR_HOUR);
        var_3 = VarGet(VAR_DAY_OF_WEEK);
        var_5 = VarGet(VAR_WEATHER_TODAY);
        if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30)
        {
            var_0 = FALSE;
        }
        else
        {
            if (VarGet(VAR_RICK_AND_KAREN_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_RICK_KAREN_WEDDING_MISSED) == TRUE || (VarGet(VAR_POPURI_AND_KAI_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_POPURI_KAI_WEDDING_MISSED) == TRUE) || (VarGet(VAR_ANN_AND_CLIFF_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_ANN_CLIFF_WEDDING_MISSED) == TRUE) || (VarGet(VAR_MARY_AND_GRAY_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_MARY_GRAY_WEDDING_MISSED) == TRUE) || (VarGet(VAR_ELLI_AND_DOCTOR_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_ELLI_DOCTOR_WEDDING_MISSED) == TRUE))
            {
                var_0 = TRUE;
            }
            else
            {
                if (VarGet(VAR_POPURI_BLUE_HEART_EVENT_CHOICE) == POPURI_BLUE_HEART_RESPONSE_RETURN_TO_WORK)
                {
                    var_0 = FALSE;
                }
                else
                {
                    if (GetNpcFriendship(CHARACTER_CARTER) <= 100)
                    {
                        if (var_4 >= 10 && var_4 < 19)
                        {
                            var_0 = TRUE;
                        }
                    }
                    else
                    {
                        if (GetNpcFriendship(CHARACTER_CARTER) > 100)
                        {
                            if (var_4 >= 8 && var_4 < 20)
                            {
                                var_0 = TRUE;
                            }
                            if (GetNpcFriendship(CHARACTER_CARTER) > 200)
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
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_CHURCH, X(184), Y(320));
            SetEntityPosition(ENTITY_PLAYER, X(184), Y(320), FACING_UP);
            if (VarGet(VAR_RICK_AND_KAREN_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_RICK_KAREN_WEDDING_MISSED) == TRUE)
            {
                CallScript(EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice);
            }
            else
            {
                if (VarGet(VAR_POPURI_AND_KAI_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_POPURI_KAI_WEDDING_MISSED) == TRUE)
                {
                    CallScript(EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice);
                }
                else
                {
                    if (VarGet(VAR_ANN_AND_CLIFF_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_ANN_CLIFF_WEDDING_MISSED) == TRUE)
                    {
                        CallScript(EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice);
                    }
                    else
                    {
                        if (VarGet(VAR_MARY_AND_GRAY_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_MARY_GRAY_WEDDING_MISSED) == TRUE)
                        {
                            CallScript(EventScript_RivalMarriageEvent_MaryAndGray_05_Wedding_AttendanceChoice);
                        }
                        else
                        {
                            if (VarGet(VAR_ELLI_AND_DOCTOR_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_ELLI_DOCTOR_WEDDING_MISSED) == TRUE)
                            {
                                CallScript(EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice);
                            }
                            else
                            {
                                if (VarGet(VAR_POPURI_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_1 == SEASON_SUMMER) && var_3 == DAY_OF_WEEK_SUNDAY && var_5 == WEATHER_SUNNY && (var_4 >= 10 && var_4 < 13) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_BLUE_MIN && IsPlayerHoldingNothing() == TRUE && (VarGet(VAR_RUCKSACK_UPGRADE_LEVEL) == RUCKSACK_UPGRADE_LARGE || VarGet(VAR_HAS_SHELF) == TRUE))
                                {
                                    VarSet(VAR_POPURI_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                    CallScript(EventScript_LoveEvent_Popuri_03_BlueHeart_PlayHouseWithChildren);
                                }
                                else
                                {
                                    if (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_1 == SEASON_FALL) && !(var_3 == DAY_OF_WEEK_SATURDAY) && (var_4 >= 11 && var_4 < 16) && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_GREEN_MIN && GetEntityLocation(ENTITY_CLIFF) == MAP_CHURCH)
                                    {
                                        VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                        CallScript(EventScript_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest);
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_CARTER_CONFESSIONAL_DREAM_PREDICTS_GOOD_FORTUNE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_3 == DAY_OF_WEEK_WEDNESDAY && (var_4 >= 16 && var_4 < 22) && HasMetNpc(CHARACTER_CARTER) == TRUE && GetNpcFriendship(CHARACTER_CARTER) >= 100)
                                        {
                                            VarSet(VAR_CARTER_CONFESSIONAL_DREAM_PREDICTS_GOOD_FORTUNE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                            CallScript(EventScript_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune);
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_CARTER_CHURCH_BACK_DOOR_MUSHROOM_SECRET_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_FALL && (var_3 == DAY_OF_WEEK_MONDAY || var_3 == DAY_OF_WEEK_WEDNESDAY) && (var_4 >= 16 && var_4 < 22) && HasMetNpc(CHARACTER_CARTER) == TRUE && GetNpcFriendship(CHARACTER_CARTER) >= 200)
                                            {
                                                VarSet(VAR_CARTER_CHURCH_BACK_DOOR_MUSHROOM_SECRET_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                CallScript(EventScript_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice);
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
            TalkMessage(gText_LocationTransition_EnterChurchWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}

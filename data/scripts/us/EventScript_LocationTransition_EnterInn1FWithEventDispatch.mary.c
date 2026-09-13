#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterInn1FWithEventDispatch_DoorIsLocked[] =
        "It's locked...{Press}";
};

void EventScript_LocationTransition_EnterInn1FWithEventDispatch(void)
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
            if (var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24)
            {
                if (VarGet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX) == STARRY_NIGHT_HOST_ANN_HOUSEHOLD)
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
                if (var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_05 && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE)
                {
                    if (GetEntityLocation(ENTITY_ANN) == MAP_INN_1F)
                    {
                        var_0 = TRUE;
                    }
                }
                else
                {
                    if (VarGet(VAR_ANN_AND_CLIFF_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_ANN_CLIFF_WEDDING_MISSED) == TRUE)
                    {
                        var_0 = FALSE;
                    }
                    else
                    {
                        if (GetNpcFriendship(CHARACTER_DOUG) <= 200)
                        {
                            if (var_4 >= 8 && var_4 < 21)
                            {
                                var_0 = TRUE;
                            }
                        }
                        else
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
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_INN_1F, X(184), Y(320));
            SetEntityPosition(ENTITY_PLAYER, X(184), Y(320), FACING_UP);
            if (var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 && VarGet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX) == STARRY_NIGHT_HOST_ANN_HOUSEHOLD)
            {
                if (var_4 >= 18)
                {
                    CallScript(EventScript_FestivalEvent_StarryNight_WithAnnFamily);
                }
            }
            if (VarGet(VAR_ANN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_3 == DAY_OF_WEEK_MONDAY || var_3 == DAY_OF_WEEK_SATURDAY) && (var_4 >= 10 && var_4 < 13) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (GetEntityLocation(ENTITY_DOUG) == MAP_INN_1F || GetEntityLocation(ENTITY_DOUG) == MAP_INN_BACK_ROOM || GetEntityLocation(ENTITY_DOUG) == MAP_INN_2F) && (GetEntityLocation(ENTITY_ANN) == MAP_INN_1F || GetEntityLocation(ENTITY_ANN) == MAP_INN_BACK_ROOM || GetEntityLocation(ENTITY_ANN) == MAP_INN_2F) && IsPlayerHoldingNothing() == TRUE)
            {
                VarSet(VAR_ANN_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                CallScript(EventScript_LoveEvent_Ann_01_BlackHeart_ReceiveWelcomeMeal);
            }
            else
            {
                if (VarGet(VAR_ANN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANN_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (var_3 == DAY_OF_WEEK_MONDAY || var_3 == DAY_OF_WEEK_FRIDAY) && (var_4 >= 12 && var_4 < 19) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_BLUE_MIN && (GetEntityLocation(ENTITY_DOUG) == MAP_INN_1F || GetEntityLocation(ENTITY_DOUG) == MAP_INN_BACK_ROOM || GetEntityLocation(ENTITY_DOUG) == MAP_INN_2F) && (GetEntityLocation(ENTITY_ANN) == MAP_INN_1F || GetEntityLocation(ENTITY_ANN) == MAP_INN_BACK_ROOM || GetEntityLocation(ENTITY_ANN) == MAP_INN_2F) && IsPlayerHoldingNothing() == TRUE && (VarGet(VAR_RUCKSACK_UPGRADE_LEVEL) == RUCKSACK_UPGRADE_LARGE || VarGet(VAR_HAS_SHELF) == TRUE))
                {
                    VarSet(VAR_ANN_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_LoveEvent_Ann_03_BlueHeart_VisitClinicAfterOvereating);
                }
                else
                {
                    if (VarGet(VAR_ANN_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_3 == DAY_OF_WEEK_MONDAY || var_3 == DAY_OF_WEEK_FRIDAY) && (var_4 >= 10 && var_4 < 19) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_YELLOW_MIN && (GetEntityLocation(ENTITY_DOUG) == MAP_INN_1F || GetEntityLocation(ENTITY_DOUG) == MAP_INN_BACK_ROOM || GetEntityLocation(ENTITY_DOUG) == MAP_INN_2F) && (GetEntityLocation(ENTITY_ANN) == MAP_INN_1F || GetEntityLocation(ENTITY_ANN) == MAP_INN_BACK_ROOM || GetEntityLocation(ENTITY_ANN) == MAP_INN_2F) && IsPlayerHoldingNothing() == TRUE)
                    {
                        VarSet(VAR_ANN_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_LoveEvent_Ann_04_YellowHeart_DougAsksAboutAnn);
                    }
                    else
                    {
                        if (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_6 >= 2 && var_3 == DAY_OF_WEEK_SATURDAY && (var_4 >= 10 && var_4 < 13) && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_YELLOW_MIN && (GetEntityLocation(ENTITY_DOUG) == MAP_INN_1F || GetEntityLocation(ENTITY_DOUG) == MAP_INN_BACK_ROOM || GetEntityLocation(ENTITY_DOUG) == MAP_INN_2F) && (GetEntityLocation(ENTITY_CLIFF) == MAP_INN_1F || GetEntityLocation(ENTITY_CLIFF) == MAP_INN_BACK_ROOM || GetEntityLocation(ENTITY_CLIFF) == MAP_INN_2F) && (GetEntityLocation(ENTITY_ANN) == MAP_INN_1F || GetEntityLocation(ENTITY_ANN) == MAP_INN_BACK_ROOM || GetEntityLocation(ENTITY_ANN) == MAP_INN_2F))
                        {
                            VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation);
                        }
                        else
                        {
                            if (VarGet(VAR_BARLEY_AND_DOUG_DISCUSS_JOANNAS_PHONE_CALL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_6 >= 2 && var_5 == WEATHER_SUNNY && var_3 == DAY_OF_WEEK_FRIDAY && (var_4 >= 16 && var_4 < 19) && GetNpcFriendship(CHARACTER_BARLEY) >= 100 && (GetEntityLocation(ENTITY_DOUG) == MAP_INN_1F || GetEntityLocation(ENTITY_DOUG) == MAP_INN_BACK_ROOM))
                            {
                                VarSet(VAR_BARLEY_AND_DOUG_DISCUSS_JOANNAS_PHONE_CALL_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall);
                            }
                            else
                            {
                                if (VarGet(VAR_BARLEY_AND_DOUG_DISCUSS_JOANNAS_PHONE_CALL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_MAY_PHONE_CALL_WITH_JOANNA_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_6 >= 3 && var_5 == WEATHER_SUNNY && var_3 == DAY_OF_WEEK_WEDNESDAY && (var_4 >= 16 && var_4 < 19) && GetNpcFriendship(CHARACTER_MAY) >= 200 && (GetEntityLocation(ENTITY_DOUG) == MAP_INN_1F || GetEntityLocation(ENTITY_DOUG) == MAP_INN_BACK_ROOM))
                                {
                                    VarSet(VAR_MAY_PHONE_CALL_WITH_JOANNA_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                    CallScript(EventScript_NPCEvent_May_PhoneCallWithJoanna);
                                }
                                else
                                {
                                    if (VarGet(VAR_KAREN_AND_DUKE_DRINKING_CONTEST_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_3 == DAY_OF_WEEK_SUNDAY && (var_4 >= 19 && var_4 < 22) && HasMetNpc(CHARACTER_KAREN) == TRUE && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_GREEN_MIN && GetEntityLocation(ENTITY_DUKE) == MAP_INN_1F && GetEntityLocation(ENTITY_KAREN) == MAP_INN_1F && (GetEntityLocation(ENTITY_DOUG) == MAP_INN_1F || GetEntityLocation(ENTITY_DOUG) == MAP_INN_BACK_ROOM))
                                    {
                                        VarSet(VAR_KAREN_AND_DUKE_DRINKING_CONTEST_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                        CallScript(EventScript_NPCEvent_KarenAndDuke_DrinkingContestAndDebtSettlement);
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_3 == DAY_OF_WEEK_SATURDAY && (var_4 >= 13 && var_4 < 16) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_PURPLE_MIN && HasMetNpc(CHARACTER_DUKE) == TRUE && HasMetNpc(CHARACTER_ANN) == TRUE && HasMetNpc(CHARACTER_HARRIS) == TRUE && HasMetNpc(CHARACTER_THOMAS) == TRUE && HasMetNpc(CHARACTER_DOUG) == TRUE && GetEntityLocation(ENTITY_DUKE) == MAP_INN_1F && (GetEntityLocation(ENTITY_ANN) == MAP_INN_1F || GetEntityLocation(ENTITY_ANN) == MAP_INN_BACK_ROOM) && GetEntityLocation(ENTITY_HARRIS) == MAP_INN_1F && GetEntityLocation(ENTITY_THOMAS) == MAP_INN_1F && (GetEntityLocation(ENTITY_DOUG) == MAP_INN_1F || GetEntityLocation(ENTITY_DOUG) == MAP_INN_BACK_ROOM))
                                        {
                                            VarSet(VAR_DOUG_AND_DUKE_ARGUMENT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                            CallScript(EventScript_NPCEvent_DougAndDuke_ArgumentChoice);
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_ANN_AND_CLIFF_SIBLING_COMPARISON_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_5 == WEATHER_RAIN && (var_4 >= 6 && var_4 < 8) && (VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                            {
                                                VarSet(VAR_ANN_AND_CLIFF_SIBLING_COMPARISON_ARGUMENT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                CallScript(EventScript_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument);
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
            TalkMessage(gText_LocationTransition_EnterInn1FWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}

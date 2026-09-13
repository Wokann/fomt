#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterSupermarketWithEventDispatch_DoorIsLocked[] =
        "Abgeschlossen...{Press}";
};

void EventScript_LocationTransition_EnterSupermarketWithEventDispatch(void)
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
        if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30)
        {
            var_0 = FALSE;
        }
        else
        {
            if (var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24)
            {
                if (VarGet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX) == STARRY_NIGHT_HOST_KAREN_HOUSEHOLD)
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
                if (VarGet(VAR_RICK_AND_KAREN_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_RICK_KAREN_WEDDING_MISSED) == TRUE)
                {
                    var_0 = FALSE;
                }
                else
                {
                    if (var_3 == DAY_OF_WEEK_SUNDAY || var_3 == DAY_OF_WEEK_TUESDAY)
                    {
                        var_0 = FALSE;
                    }
                    else
                    {
                        if (GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET)
                        {
                            if (GetNpcFriendship(CHARACTER_JEFF) <= 100)
                            {
                                if (var_4 >= 9 && var_4 < 17)
                                {
                                    var_0 = TRUE;
                                }
                            }
                            else
                            {
                                if (GetNpcFriendship(CHARACTER_JEFF) > 100)
                                {
                                    if (var_4 >= 8 && var_4 < 18)
                                    {
                                        var_0 = TRUE;
                                    }
                                    if (GetNpcFriendship(CHARACTER_JEFF) > 200)
                                    {
                                        if (var_4 >= 6 && var_4 < 18)
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
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_SUPERMARKET, X(144), Y(320));
            SetEntityPosition(ENTITY_PLAYER, X(144), Y(320), FACING_UP);
            if (var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 && VarGet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX) == STARRY_NIGHT_HOST_KAREN_HOUSEHOLD)
            {
                if (var_4 >= 18)
                {
                    CallScript(EventScript_FestivalEvent_StarryNight_WithKarenFamily);
                }
            }
            else
            {
                if (VarGet(VAR_KAREN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_KAREN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (var_3 == DAY_OF_WEEK_MONDAY || var_3 == DAY_OF_WEEK_THURSDAY || var_3 == DAY_OF_WEEK_SATURDAY) && (var_4 >= 10 && var_4 < 13) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_PURPLE_MIN && (GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET_BACK_ROOM) && (GetEntityLocation(ENTITY_KAREN) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_KAREN) == MAP_SUPERMARKET_BACK_ROOM) && (GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET_BACK_ROOM) && IsPlayerHoldingNothing() == TRUE)
                {
                    VarSet(VAR_KAREN_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds);
                }
                else
                {
                    if (VarGet(VAR_KAREN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_KAREN_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_5 == WEATHER_SUNNY && (var_3 == DAY_OF_WEEK_WEDNESDAY || var_3 == DAY_OF_WEEK_FRIDAY) && (var_4 >= 10 && var_4 < 13) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_BLUE_MIN && (GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET_BACK_ROOM) && (GetEntityLocation(ENTITY_KAREN) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_KAREN) == MAP_SUPERMARKET_BACK_ROOM) && (GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET_BACK_ROOM) && IsPlayerHoldingNothing() == TRUE && (VarGet(VAR_RUCKSACK_UPGRADE_LEVEL) == RUCKSACK_UPGRADE_LARGE || VarGet(VAR_HAS_SHELF) == TRUE))
                    {
                        VarSet(VAR_KAREN_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine);
                    }
                    else
                    {
                        if (VarGet(VAR_KAREN_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_KAREN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (var_3 == DAY_OF_WEEK_MONDAY || var_3 == DAY_OF_WEEK_THURSDAY || var_3 == DAY_OF_WEEK_SATURDAY) && (var_4 >= 10 && var_4 < 13) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_YELLOW_MIN && (GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET_BACK_ROOM) && (GetEntityLocation(ENTITY_KAREN) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_KAREN) == MAP_SUPERMARKET_BACK_ROOM) && (GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET_BACK_ROOM) && IsPlayerHoldingNothing() == TRUE)
                        {
                            VarSet(VAR_KAREN_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking);
                        }
                        else
                        {
                            if (VarGet(VAR_MANNA_FLATTERS_JEFF_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE && !(var_3 == DAY_OF_WEEK_MONDAY || var_3 == DAY_OF_WEEK_WEDNESDAY || var_3 == DAY_OF_WEEK_SATURDAY) && (var_4 >= 13 && var_4 < 16) && GetEntityLocation(ENTITY_MANNA) == MAP_SUPERMARKET && HasMetNpc(CHARACTER_MANNA) == TRUE && GetNpcFriendship(CHARACTER_MANNA) >= 100)
                            {
                                VarSet(VAR_MANNA_FLATTERS_JEFF_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_NPCEvent_Manna_FlattersJeff);
                            }
                            else
                            {
                                if (VarGet(VAR_WON_OFFERS_TO_BUY_JEFFS_PAINTING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_3 == DAY_OF_WEEK_MONDAY && (var_4 >= 8 && var_4 < 10) && (VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && GetNpcFriendship(CHARACTER_JEFF) >= 200 && GetNpcFriendship(CHARACTER_SASHA) >= 200 && HasMetNpc(CHARACTER_JEFF) == TRUE && HasMetNpc(CHARACTER_SASHA) == TRUE && (GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET_BACK_ROOM) && (GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET_BACK_ROOM))
                                {
                                    VarSet(VAR_WON_OFFERS_TO_BUY_JEFFS_PAINTING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                    CallScript(EventScript_NPCEvent_Jeff_WonOffersToBuyPainting);
                                }
                                else
                                {
                                    if (VarGet(VAR_JEFF_AND_SASHA_STORE_CREDIT_LESSON_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_5 == WEATHER_RAIN && var_3 == DAY_OF_WEEK_WEDNESDAY && (var_4 >= 13 && var_4 < 16) && (VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && GetNpcFriendship(CHARACTER_JEFF) >= 250 && GetNpcFriendship(CHARACTER_SASHA) >= 250 && HasMetNpc(CHARACTER_JEFF) == TRUE && HasMetNpc(CHARACTER_SASHA) == TRUE && (GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET_BACK_ROOM) && (GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET_BACK_ROOM))
                                    {
                                        VarSet(VAR_JEFF_AND_SASHA_STORE_CREDIT_LESSON_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                        CallScript(EventScript_NPCEvent_JeffAndSasha_StoreCreditLesson);
                                    }
                                    else
                                    {
                                        if (GetFirstFreeRucksackToolSlot() >= RUCKSACK_SLOT_1 || GetPlayerHeldToolId() == mary_negated_int(ITEM_TOOL_NOT_PRESENT))
                                        {
                                            if (VarGet(VAR_KAREN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (var_3 == DAY_OF_WEEK_WEDNESDAY || var_3 == DAY_OF_WEEK_FRIDAY) && (var_4 >= 10 && var_4 < 13) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_JEFF) == MAP_SUPERMARKET_BACK_ROOM) && (GetEntityLocation(ENTITY_KAREN) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_KAREN) == MAP_SUPERMARKET_BACK_ROOM) && (GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET || GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET_BACK_ROOM) && IsPlayerHoldingNothing() == TRUE)
                                            {
                                                VarSet(VAR_KAREN_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                CallScript(EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift);
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
            TalkMessage(gText_LocationTransition_EnterSupermarketWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}

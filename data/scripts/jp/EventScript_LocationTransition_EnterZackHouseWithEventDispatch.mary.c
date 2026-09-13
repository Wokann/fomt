#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterZackHouseWithEventDispatch_DoorIsLocked[] =
        "カギがかかっている…{Press}";
};

void EventScript_LocationTransition_EnterZackHouseWithEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_SEASON);
        var_2 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        var_4 = VarGet(VAR_DAY_OF_WEEK);
        var_5 = VarGet(VAR_WEATHER_TODAY);
        if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30)
        {
            var_0 = FALSE;
        }
        else
        {
            if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_KAI_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_KAI_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                var_0 = FALSE;
            }
            else
            {
                if (GetEntityLocation(ENTITY_ZACK) == MAP_ZACK_HOUSE)
                {
                    if (GetNpcFriendship(CHARACTER_ZACK) <= 100)
                    {
                        if (var_3 >= 10 && var_3 < 19)
                        {
                            var_0 = TRUE;
                        }
                    }
                    else
                    {
                        if (GetNpcFriendship(CHARACTER_ZACK) > 100)
                        {
                            if (var_3 >= 8 && var_3 < 20)
                            {
                                var_0 = TRUE;
                            }
                            if (GetNpcFriendship(CHARACTER_ZACK) > 200)
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
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_ZACK_HOUSE, X(120), Y(208));
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
            if (VarGet(VAR_POPURI_PLANS_LILLIA_BIRTHDAY_GIFT_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_SPRING && (var_3 >= 10 && var_3 < 15) && (var_2 >= DAY_OF_MONTH_10 && var_2 <= DAY_OF_MONTH_17) && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && HasMetNpc(CHARACTER_POPURI) == TRUE && HasMetNpc(CHARACTER_ZACK) == TRUE && HasMetNpc(CHARACTER_WON) == TRUE && GetEntityLocation(ENTITY_ZACK) == MAP_ZACK_HOUSE && GetEntityLocation(ENTITY_WON) == MAP_ZACK_HOUSE)
            {
                VarSet(VAR_POPURI_PLANS_LILLIA_BIRTHDAY_GIFT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                CallScript(EventScript_NPCEvent_Popuri_PlansLilliaBirthdayGift);
            }
            else
            {
                if (VarGet(VAR_WON_AND_KAREN_FIRST_MEETING_AT_ZACKS_HOUSE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_4 == DAY_OF_WEEK_SUNDAY || var_4 == DAY_OF_WEEK_TUESDAY) && var_5 == WEATHER_SUNNY && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && HasMetNpc(CHARACTER_KAREN) == TRUE && HasMetNpc(CHARACTER_ZACK) == TRUE && HasMetNpc(CHARACTER_WON) == TRUE && GetEntityLocation(ENTITY_ZACK) == MAP_ZACK_HOUSE && GetEntityLocation(ENTITY_WON) == MAP_ZACK_HOUSE)
                {
                    VarSet(VAR_WON_AND_KAREN_FIRST_MEETING_AT_ZACKS_HOUSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse);
                }
                else
                {
                    if (GetFirstFreeRucksackToolSlot() >= RUCKSACK_SLOT_1 || GetPlayerHeldToolId() == mary_negated_int(ITEM_TOOL_NOT_PRESENT))
                    {
                        if (VarGet(VAR_ZACK_GIVES_FISHING_ROD_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && HasMetNpc(CHARACTER_ZACK) == TRUE)
                        {
                            VarSet(VAR_ZACK_GIVES_FISHING_ROD_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_NPCEvent_Zack_GivesFishingRod);
                        }
                    }
                }
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterZackHouseWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}

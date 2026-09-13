#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterKaiRestaurantWithEventDispatch_DoorIsLocked[] =
        "It's locked...{Press}";
};

void EventScript_LocationTransition_EnterKaiRestaurantWithEventDispatch(void)
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
                if (GetEntityLocation(ENTITY_KAI) == MAP_KAI_RESTAURANT)
                {
                    if (var_3 >= 11 && var_3 < 13 || var_3 >= 17 && var_3 < 19)
                    {
                        var_0 = TRUE;
                    }
                }
            }
        }
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_KAI_RESTAURANT, X(120), Y(208));
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
            if (VarGet(VAR_POPURI_ASKS_KAI_FOR_NECKLACE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_SUMMER && var_5 == WEATHER_SUNNY && (var_3 >= 17 && var_3 < 19) && (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                VarSet(VAR_POPURI_ASKS_KAI_FOR_NECKLACE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                CallScript(EventScript_NPCEvent_Popuri_AsksKaiForNecklace);
            }
            else
            {
                if (VarGet(VAR_GRAY_AND_KAI_FRIENDSHIP_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_SUMMER && (var_3 >= 11 && var_3 < 13) && GetNpcFriendship(CHARACTER_GRAY) >= 100 && GetNpcFriendship(CHARACTER_KAI) >= 100 && HasMetNpc(CHARACTER_GRAY) == TRUE && HasMetNpc(CHARACTER_KAI) == TRUE)
                {
                    VarSet(VAR_GRAY_AND_KAI_FRIENDSHIP_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_NPCEvent_GrayAndKai_KaiCooksForGray);
                }
                else
                {
                    if (VarGet(VAR_POPURI_BRINGS_CUSTOMERS_TO_KAIS_BEACH_CAFE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_SUMMER && var_5 == WEATHER_SUNNY && (var_3 >= 17 && var_3 < 19) && GetNpcFriendship(CHARACTER_KAI) >= 100 && (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE) && HasMetNpc(CHARACTER_POPURI) == TRUE && HasMetNpc(CHARACTER_KAI) == TRUE)
                    {
                        VarSet(VAR_POPURI_BRINGS_CUSTOMERS_TO_KAIS_BEACH_CAFE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe);
                    }
                }
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterKaiRestaurantWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}

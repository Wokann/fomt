#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterBlacksmithWithEventDispatch_DoorIsLocked[] =
        "It's locked...{Press}";
};

void EventScript_LocationTransition_EnterBlacksmithWithEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_SEASON);
        var_2 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        var_4 = VarGet(VAR_DAY_OF_WEEK);
        if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30)
        {
            var_0 = FALSE;
        }
        else
        {
            if (VarGet(VAR_MARY_AND_GRAY_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_MARY_GRAY_WEDDING_MISSED) == TRUE)
            {
                var_0 = FALSE;
            }
            else
            {
                if (GetEntityLocation(ENTITY_SAIBARA) == MAP_BLACKSMITH)
                {
                    if (GetNpcFriendship(CHARACTER_SAIBARA) <= 100)
                    {
                        if (var_3 >= 10 && var_3 < 19)
                        {
                            if (GetBlacksmithOrderId() == BLACKSMITH_ORDER_NONE)
                            {
                                var_0 = TRUE;
                            }
                            else
                            {
                                if (IsBlacksmithOrderReady())
                                {
                                    var_0 = TRUE;
                                }
                                else
                                {
                                    var_0 = FALSE;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (GetNpcFriendship(CHARACTER_SAIBARA) > 100)
                        {
                            if (var_3 >= 8 && var_3 < 20)
                            {
                                if (GetBlacksmithOrderId() == BLACKSMITH_ORDER_NONE)
                                {
                                    var_0 = TRUE;
                                }
                                else
                                {
                                    if (IsBlacksmithOrderReady())
                                    {
                                        var_0 = TRUE;
                                    }
                                    else
                                    {
                                        var_0 = FALSE;
                                    }
                                }
                            }
                            if (GetNpcFriendship(CHARACTER_SAIBARA) > 200)
                            {
                                if (var_3 >= 6 && var_3 < 22)
                                {
                                    if (GetBlacksmithOrderId() == BLACKSMITH_ORDER_NONE)
                                    {
                                        var_0 = TRUE;
                                    }
                                    else
                                    {
                                        if (IsBlacksmithOrderReady())
                                        {
                                            var_0 = TRUE;
                                        }
                                        else
                                        {
                                            var_0 = FALSE;
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
            ChangeMap(MAP_BLACKSMITH, X(120), Y(208));
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
            if (VarGet(VAR_MARY_GRAY_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_4 != DAY_OF_WEEK_MONDAY && (var_3 >= 10 && var_3 < 13) && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_MARY) < LOVE_HEART_PURPLE_MIN && GetEntityLocation(ENTITY_GRAY) == MAP_BLACKSMITH && HasMetNpc(CHARACTER_MARY) == TRUE && HasMetNpc(CHARACTER_GRAY) == TRUE && GetEntityLocation(ENTITY_SAIBARA) == MAP_BLACKSMITH)
            {
                VarSet(VAR_MARY_GRAY_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                CallScript(EventScript_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury);
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterBlacksmithWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}

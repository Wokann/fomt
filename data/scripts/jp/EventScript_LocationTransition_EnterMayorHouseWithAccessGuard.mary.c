#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterMayorHouseWithAccessGuard_DoorIsLocked[] =
        "カギがかかっている…{Press}";
};

void EventScript_LocationTransition_EnterMayorHouseWithAccessGuard(void)
{
    int var_0, var_1, var_2, var_3;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_HOUR);
        var_2 = VarGet(VAR_SEASON);
        var_3 = VarGet(VAR_DAY);
        if (var_2 == SEASON_SPRING && var_3 == DAY_OF_MONTH_01 || var_2 == SEASON_SPRING && var_3 == DAY_OF_MONTH_18 || var_2 == SEASON_SPRING && var_3 == DAY_OF_MONTH_22 || var_2 == SEASON_SUMMER && var_3 == DAY_OF_MONTH_01 || var_2 == SEASON_SUMMER && var_3 == DAY_OF_MONTH_07 || var_2 == SEASON_SUMMER && var_3 == DAY_OF_MONTH_24 || var_2 == SEASON_SUMMER && var_3 == DAY_OF_MONTH_20 || var_2 == SEASON_FALL && var_3 == DAY_OF_MONTH_03 || var_2 == SEASON_FALL && var_3 == DAY_OF_MONTH_09 || var_2 == SEASON_FALL && var_3 == DAY_OF_MONTH_13 || var_2 == SEASON_FALL && var_3 == DAY_OF_MONTH_18 || var_2 == SEASON_FALL && var_3 == DAY_OF_MONTH_21 || var_2 == SEASON_WINTER && var_3 == DAY_OF_MONTH_24 || var_2 == SEASON_WINTER && var_3 == DAY_OF_MONTH_30)
        {
            var_0 = FALSE;
        }
        else
        {
            if (GetEntityLocation(ENTITY_THOMAS) == MAP_MAYOR_HOUSE)
            {
                if (GetNpcFriendship(CHARACTER_THOMAS) <= 100)
                {
                    if (var_1 >= 10 && var_1 < 19)
                    {
                        var_0 = TRUE;
                    }
                }
                else
                {
                    if (GetNpcFriendship(CHARACTER_THOMAS) > 100)
                    {
                        if (var_1 >= 8 && var_1 < 20)
                        {
                            var_0 = TRUE;
                        }
                        if (GetNpcFriendship(CHARACTER_THOMAS) > 200)
                        {
                            if (var_1 >= 6 && var_1 < 22)
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
            ChangeMap(MAP_MAYOR_HOUSE, X(120), Y(208));
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterMayorHouseWithAccessGuard_DoorIsLocked);
            TalkClose();
        }
    }
}

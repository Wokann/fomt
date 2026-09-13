#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterYodelRanchHouse1FWithAccessGuard_DoorIsLocked[] =
        "Abgeschlossen...{Press}";
};

void EventScript_LocationTransition_EnterYodelRanchHouse1FWithAccessGuard(void)
{
    int var_0, var_1, var_2, var_3;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_SEASON);
        var_2 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30)
        {
            var_0 = FALSE;
        }
        else
        {
            if (GetEntityLocation(ENTITY_BARLEY) == MAP_YODEL_RANCH_HOUSE_1F)
            {
                if (GetNpcFriendship(CHARACTER_BARLEY) <= 100)
                {
                    if (var_3 >= 10 && var_3 < 19)
                    {
                        var_0 = TRUE;
                    }
                }
                else
                {
                    if (GetNpcFriendship(CHARACTER_BARLEY) > 100)
                    {
                        if (var_3 >= 8 && var_3 < 20)
                        {
                            var_0 = TRUE;
                        }
                        if (GetNpcFriendship(CHARACTER_BARLEY) > 200)
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
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_YODEL_RANCH_HOUSE_1F, X(168), Y(208));
            SetEntityPosition(ENTITY_PLAYER, X(168), Y(208), FACING_UP);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterYodelRanchHouse1FWithAccessGuard_DoorIsLocked);
            TalkClose();
        }
    }
}

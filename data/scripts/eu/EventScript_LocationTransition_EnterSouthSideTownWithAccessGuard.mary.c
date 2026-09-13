#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterSouthSideTownWithAccessGuard_DoorIsLocked[] =
        "It's locked...{Press}";
};

void EventScript_LocationTransition_EnterSouthSideTownWithAccessGuard(void)
{
    int unused_0, var_1, var_2;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        var_2 = FALSE;
        var_1 = VarGet(VAR_WEATHER_TODAY);
        if (var_1 == WEATHER_SUNNY)
        {
            var_2 = TRUE;
        }
        if (var_2 == TRUE)
        {
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_SOUTH_SIDE_TOWN, X(944), Y(232));
            SetEntityPosition(ENTITY_PLAYER, X(944), Y(232), FACING_DOWN);
            PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterSouthSideTownWithAccessGuard_DoorIsLocked);
            TalkClose();
        }
    }
}

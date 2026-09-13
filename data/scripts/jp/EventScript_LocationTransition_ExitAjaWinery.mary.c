#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitAjaWinery(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_DUKE_AND_MANNA_MISSING_JUICE_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_DUKE_AND_MANNA_MISSING_JUICE_ARGUMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_MANNA);
            ClearEntityEventScript(ENTITY_DUKE);
            DisableScriptedNpcControl();
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_NORTH_SIDE_TOWN, X(232), Y(488));
        SetEntityPosition(ENTITY_PLAYER, X(232), Y(488), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

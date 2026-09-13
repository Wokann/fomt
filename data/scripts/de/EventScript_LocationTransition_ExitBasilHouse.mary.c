#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitBasilHouse(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_BASIL_PUBLISHING_AWARD_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_BASIL_PUBLISHING_AWARD_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_BASIL);
            ClearEntityEventScript(ENTITY_ANNA);
            ClearEntityEventScript(ENTITY_MARY);
            ClearEntityEventScript(ENTITY_GRAY);
            DisableScriptedNpcControl();
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_NORTH_SIDE_TOWN, X(200), Y(168));
        SetEntityPosition(ENTITY_PLAYER, X(200), Y(168), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

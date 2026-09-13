#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitSeasideLodge(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        if (VarGet(VAR_ZACK_GIVES_FISHING_ROD_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            DisableScriptedNpcControl();
            ClearEntityEventScript(ENTITY_ZACK);
            ClearEntityEventScript(ENTITY_WON);
            VarSet(VAR_ZACK_GIVES_FISHING_ROD_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        else
        {
            if (VarGet(VAR_WON_AND_KAREN_FIRST_MEETING_AT_ZACKS_HOUSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                DisableScriptedNpcControl();
                ClearEntityEventScript(ENTITY_ZACK);
                ClearEntityEventScript(ENTITY_WON);
                VarSet(VAR_WON_AND_KAREN_FIRST_MEETING_AT_ZACKS_HOUSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            }
        }
        ChangeMap(MAP_MINERAL_BEACH, X(212), Y(120));
        SetEntityPosition(ENTITY_PLAYER, X(212), Y(120), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

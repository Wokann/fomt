#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitLibraryWithEventStateCleanup(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_MARY_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_MARY_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_MARY);
            DisableScriptedNpcControl();
        }
        else
        {
            if (VarGet(VAR_MARY_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                VarSet(VAR_MARY_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                ClearEntityEventScript(ENTITY_MARY);
                DisableScriptedNpcControl();
            }
            else
            {
                if (VarGet(VAR_MARY_GRAY_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    VarSet(VAR_MARY_GRAY_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                    ClearEntityEventScript(ENTITY_MARY);
                    ClearEntityEventScript(ENTITY_GRAY);
                    DisableScriptedNpcControl();
                }
                else
                {
                    if (VarGet(VAR_MARY_GRAY_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        VarSet(VAR_MARY_GRAY_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_COMPLETED);
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_GRAY);
                        DisableScriptedNpcControl();
                    }
                }
            }
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_NORTH_SIDE_TOWN, X(276), Y(176));
        SetEntityPosition(ENTITY_PLAYER, X(276), Y(176), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

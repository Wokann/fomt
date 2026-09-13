#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitInnWithEventStateCleanup(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_ANN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_ANN_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_ANN);
            ClearEntityEventScript(ENTITY_DOUG);
            DisableScriptedNpcControl();
        }
        else
        {
            if (VarGet(VAR_ANN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                VarSet(VAR_ANN_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                ClearEntityEventScript(ENTITY_DOUG);
                DisableScriptedNpcControl();
            }
            else
            {
                if (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_COMPLETED);
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_DOUG);
                    ClearEntityEventScript(ENTITY_CLIFF);
                    DisableScriptedNpcControl();
                }
                else
                {
                    if (VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        VarSet(VAR_DOUG_AND_DUKE_ARGUMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_DOUG);
                        ClearEntityEventScript(ENTITY_DUKE);
                        ClearEntityEventScript(ENTITY_THOMAS);
                        ClearEntityEventScript(ENTITY_HARRIS);
                        DisableScriptedNpcControl();
                    }
                }
            }
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_NORTH_SIDE_TOWN, X(632), Y(496));
        SetEntityPosition(ENTITY_PLAYER, X(632), Y(496), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

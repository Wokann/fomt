#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_Inn2FTo1FWithEventStateCleanup(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_ANN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_ANN_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_ANN);
            DisableScriptedNpcControl();
        }
        else
        {
            if (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                ClearEntityEventScript(ENTITY_CLIFF);
                DisableScriptedNpcControl();
            }
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_INN_1F, X(40), Y(96));
        SetEntityPosition(ENTITY_PLAYER, X(40), Y(96), FACING_DOWN);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

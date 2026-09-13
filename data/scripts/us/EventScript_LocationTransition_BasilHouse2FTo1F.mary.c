#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_BasilHouse2FTo1F(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_BASIL_LETTER_ADVICE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_BASIL_LETTER_ADVICE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_BASIL);
            DisableScriptedNpcControl();
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_BASIL_HOUSE_1F, X(216), Y(144));
        SetEntityPosition(ENTITY_PLAYER, X(216), Y(144), FACING_DOWN);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

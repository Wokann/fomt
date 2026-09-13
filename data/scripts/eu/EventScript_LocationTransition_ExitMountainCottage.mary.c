#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitMountainCottage(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_RIGHT)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        if (VarGet(VAR_DOCTOR_REFLECTS_ON_PARENTS_AND_MEDICAL_CALLING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            DisableScriptedNpcControl();
            ClearEntityEventScript(ENTITY_DOCTOR);
            AddNpcFriendship(CHARACTER_DOCTOR, 20);
            VarSet(VAR_DOCTOR_REFLECTS_ON_PARENTS_AND_MEDICAL_CALLING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        ChangeMap(MAP_FOREST, X(24), Y(448));
        SetEntityPosition(ENTITY_PLAYER, X(24), Y(448), FACING_RIGHT);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

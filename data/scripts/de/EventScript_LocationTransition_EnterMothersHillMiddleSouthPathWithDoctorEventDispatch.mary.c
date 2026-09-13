#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterMothersHillMiddleSouthPathWithDoctorEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_LEFT)
    {
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_2 = VarGet(VAR_HOUR);
        var_3 = VarGet(VAR_DAY_OF_WEEK);
        var_4 = VarGet(VAR_WEATHER_TODAY);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_MOTHERS_HILL_MIDDLE, X(1175), Y(752));
        SetEntityPosition(ENTITY_PLAYER, X(1175), Y(752), FACING_LEFT);
        if (VarGet(VAR_DOCTOR_REFLECTS_ON_PARENTS_AND_MEDICAL_CALLING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_3 == DAY_OF_WEEK_WEDNESDAY && (var_2 >= 8 && var_2 < 10) && GetNpcFriendship(CHARACTER_DOCTOR) >= 100 && HasMetNpc(CHARACTER_DOCTOR) == TRUE && GetEntityLocation(ENTITY_DOCTOR) == MAP_MOTHERS_HILL_MIDDLE)
        {
            VarSet(VAR_DOCTOR_REFLECTS_ON_PARENTS_AND_MEDICAL_CALLING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            CallScript(EventScript_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling);
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

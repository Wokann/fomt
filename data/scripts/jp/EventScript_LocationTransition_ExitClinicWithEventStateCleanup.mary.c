#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitClinicWithEventStateCleanup(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_ELLI_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_ELLI_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_ELLI);
            ClearEntityEventScript(ENTITY_DOCTOR);
            DisableScriptedNpcControl();
        }
        else
        {
            if (VarGet(VAR_ELLI_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                VarSet(VAR_ELLI_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                ClearEntityEventScript(ENTITY_ELLI);
                ClearEntityEventScript(ENTITY_DOCTOR);
                DisableScriptedNpcControl();
            }
            else
            {
                if (VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_DOCTOR);
                    DisableScriptedNpcControl();
                }
                else
                {
                    if (VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_COMPLETED);
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_DOCTOR);
                        DisableScriptedNpcControl();
                    }
                    else
                    {
                        if (VarGet(VAR_JEFF_BLOOD_TYPE_CORRECTION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                        {
                            VarSet(VAR_JEFF_BLOOD_TYPE_CORRECTION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                            ClearEntityEventScript(ENTITY_ELLI);
                            ClearEntityEventScript(ENTITY_JEFF);
                            ClearEntityEventScript(ENTITY_DOCTOR);
                            DisableScriptedNpcControl();
                        }
                        else
                        {
                            if (VarGet(VAR_ELLI_STUDIES_MEDICINE_FOR_ELLENS_LEGS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                            {
                                VarSet(VAR_ELLI_STUDIES_MEDICINE_FOR_ELLENS_LEGS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                ClearEntityEventScript(ENTITY_ELLI);
                                ClearEntityEventScript(ENTITY_DOCTOR);
                                DisableScriptedNpcControl();
                            }
                        }
                    }
                }
            }
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_NORTH_SIDE_TOWN, X(856), Y(168));
        SetEntityPosition(ENTITY_PLAYER, X(856), Y(168), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

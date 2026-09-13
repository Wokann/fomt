#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitEllenHouseWithEventStateCleanup(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_ELLI_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_ELLI_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_ELLI);
            ClearEntityEventScript(ENTITY_ELLEN);
            ClearEntityEventScript(ENTITY_STU);
            DisableScriptedNpcControl();
        }
        else
        {
            if (VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                ClearEntityEventScript(ENTITY_ELLEN);
                ClearEntityEventScript(ENTITY_STU);
                DisableScriptedNpcControl();
            }
            else
            {
                if (VarGet(VAR_SAIBARA_VISITS_ELLEN_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    VarSet(VAR_SAIBARA_VISITS_ELLEN_EVENT_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                }
                else
                {
                    if (VarGet(VAR_SAIBARA_VISITS_ELLEN_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        VarSet(VAR_SAIBARA_VISITS_ELLEN_EVENT_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                    }
                    else
                    {
                        if (VarGet(VAR_ELLEN_WHITE_FLOWER_LEGEND_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                        {
                            VarSet(VAR_ELLEN_WHITE_FLOWER_LEGEND_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                            ClearEntityEventScript(ENTITY_ELLEN);
                            DisableScriptedNpcControl();
                        }
                        else
                        {
                            if (VarGet(VAR_ELLEN_GRANDFATHERS_HIDDEN_LETTER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                            {
                                VarSet(VAR_ELLEN_GRANDFATHERS_HIDDEN_LETTER_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                ClearEntityEventScript(ENTITY_ELLEN);
                                ClearEntityEventScript(ENTITY_ELLI);
                                ClearEntityEventScript(ENTITY_STU);
                                DisableScriptedNpcControl();
                            }
                        }
                    }
                }
            }
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_NORTH_SIDE_TOWN, X(400), Y(168));
        SetEntityPosition(ENTITY_PLAYER, X(400), Y(168), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

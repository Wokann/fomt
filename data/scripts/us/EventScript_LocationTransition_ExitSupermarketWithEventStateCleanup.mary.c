#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitSupermarketWithEventStateCleanup(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_KAREN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_KAREN_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_KAREN);
            ClearEntityEventScript(ENTITY_SASHA);
            ClearEntityEventScript(ENTITY_JEFF);
            DisableScriptedNpcControl();
        }
        else
        {
            if (VarGet(VAR_KAREN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                VarSet(VAR_KAREN_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                ClearEntityEventScript(ENTITY_KAREN);
                ClearEntityEventScript(ENTITY_SASHA);
                ClearEntityEventScript(ENTITY_JEFF);
                DisableScriptedNpcControl();
            }
            else
            {
                if (VarGet(VAR_KAREN_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    VarSet(VAR_KAREN_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_SASHA);
                    ClearEntityEventScript(ENTITY_JEFF);
                    ClearEntityEventScript(ENTITY_DUKE);
                    DisableScriptedNpcControl();
                }
                else
                {
                    if (VarGet(VAR_KAREN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        VarSet(VAR_KAREN_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_SASHA);
                        ClearEntityEventScript(ENTITY_JEFF);
                        DisableScriptedNpcControl();
                    }
                    else
                    {
                        if (VarGet(VAR_MANNA_FLATTERS_JEFF_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                        {
                            VarSet(VAR_MANNA_FLATTERS_JEFF_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                            ClearEntityEventScript(ENTITY_MANNA);
                            ClearEntityEventScript(ENTITY_JEFF);
                            DisableScriptedNpcControl();
                        }
                        else
                        {
                            if (VarGet(VAR_JEFF_AND_SASHA_STORE_CREDIT_LESSON_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                            {
                                VarSet(VAR_JEFF_AND_SASHA_STORE_CREDIT_LESSON_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                ClearEntityEventScript(ENTITY_JEFF);
                                ClearEntityEventScript(ENTITY_SASHA);
                                DisableScriptedNpcControl();
                            }
                        }
                    }
                }
            }
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_NORTH_SIDE_TOWN, X(688), Y(168));
        SetEntityPosition(ENTITY_PLAYER, X(688), Y(168), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterMountainCottage(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        if (VarGet(VAR_DOCTOR_REFLECTS_ON_PARENTS_AND_MEDICAL_CALLING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            DisableScriptedNpcControl();
            ClearEntityEventScript(ENTITY_DOCTOR);
            AddNpcFriendship(CHARACTER_DOCTOR, 20);
            VarSet(VAR_DOCTOR_REFLECTS_ON_PARENTS_AND_MEDICAL_CALLING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        ChangeMap(MAP_MOUNTAIN_COTTAGE, X(120), Y(208));
        SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
        if (IsFireplaceLitAtLocation(MAP_MOUNTAIN_COTTAGE))
        {
            switch (VarGet(VAR_SEASON))
            {
                case SEASON_SPRING:
                    ChangePlayerStaminaAndFatigue(0, 1);
                    break;
                case SEASON_SUMMER:
                    ChangePlayerStaminaAndFatigue(0, 2);
                    break;
                case SEASON_FALL:
                    ChangePlayerStaminaAndFatigue(0, 1);
                    break;
                case SEASON_WINTER:
                    ChangePlayerStaminaAndFatigue(0, mary_negated_int(-1));
                    break;
            }
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

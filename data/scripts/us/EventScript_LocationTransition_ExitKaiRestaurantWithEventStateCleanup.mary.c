#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitKaiRestaurantWithEventStateCleanup(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_POPURI_ASKS_KAI_FOR_NECKLACE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_POPURI_ASKS_KAI_FOR_NECKLACE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_KAI);
            DisableScriptedNpcControl();
        }
        else
        {
            if (VarGet(VAR_GRAY_AND_KAI_FRIENDSHIP_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                VarSet(VAR_GRAY_AND_KAI_FRIENDSHIP_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                ClearEntityEventScript(ENTITY_KAI);
                DisableScriptedNpcControl();
                MarkNpcSpokenTo(CHARACTER_KAI);
                AddNpcFriendship(CHARACTER_KAI, 20);
                MarkNpcSpokenTo(CHARACTER_GRAY);
                AddNpcFriendship(CHARACTER_GRAY, 20);
            }
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_MINERAL_BEACH, X(84), Y(120));
        SetEntityPosition(ENTITY_PLAYER, X(84), Y(120), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

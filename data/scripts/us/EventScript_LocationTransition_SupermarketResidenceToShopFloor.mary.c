#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_SupermarketResidenceToShopFloor(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_WON_OFFERS_TO_BUY_JEFFS_PAINTING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_WON_OFFERS_TO_BUY_JEFFS_PAINTING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_SASHA);
            DisableScriptedNpcControl();
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_SUPERMARKET, X(100), Y(64));
        SetEntityPosition(ENTITY_PLAYER, X(100), Y(64), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}

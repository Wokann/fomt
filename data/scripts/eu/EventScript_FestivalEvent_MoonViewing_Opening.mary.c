#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_MoonViewing_Opening(void)
{
    int var_0, var_1;
    VarSet(VAR_MOON_VIEWING_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    switch (VarGet(VAR_FESTIVAL_MOON_VIEWING_PARTNER_INDEX))
    {
        case FESTIVAL_MOON_VIEWING_PARTNER_KAREN:
            var_0 = ENTITY_KAREN;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_ANN:
            var_0 = ENTITY_ANN;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_POPURI:
            var_0 = ENTITY_POPURI;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_MARY:
            var_0 = ENTITY_MARY;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_ELLI:
            var_0 = ENTITY_ELLI;
            break;
    }
    switch (var_0)
    {
        case ENTITY_KAREN:
            var_1 = ANIMATION_KAREN_IDLE;
            break;
        case ENTITY_POPURI:
            var_1 = ANIMATION_POPURI_IDLE;
            break;
        case ENTITY_MARY:
            var_1 = ANIMATION_MARY_IDLE;
            break;
        case ENTITY_ANN:
            var_1 = ANIMATION_ANN_IDLE;
            break;
        case ENTITY_ELLI:
            var_1 = ANIMATION_ELLI_IDLE;
            break;
    }
    ChangeMap(MAP_MOTHERS_HILL_SUMMIT, X(236), Y(255));
    PlayBGM(AUDIO_START_WEAK, AUDIO_AMBIENCE_NIGHT);
    SetEntityPosition(ENTITY_PLAYER, X(236), Y(428), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(var_0, X(254), Y(244), FACING_UP);
    SetEntityAnim(var_0, var_1);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(236), Y(428), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(var_0, EventScript_FestivalEvent_MoonViewing_Choice);
}

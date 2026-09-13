#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_SystemEvent_ReturnHomeAndAdvanceToNextDay(void)
{
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    RelocateEntityToMap(ENTITY_PLAYER, MAP_FARMHOUSE, X(0), Y(0));
    ClearPreservedPlayerLocation();
    CallScript(EventScript_SystemEvent_AdvanceToNextDay);
}

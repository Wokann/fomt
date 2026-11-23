#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_0339_MineEvent_ReturnToMothersHillDispatcher(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        CallScript(EventScript_0977_LocationTransition_ReturnToMothersHillWithRivalEventDispatch);
    }
}

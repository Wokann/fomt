#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0154_LocationInteraction_InspectBeehive.mary.h"

void EventScript_0154_LocationInteraction_InspectBeehive(void)
{
    if (!IsPlayerRidingHorse() && IsPlayerHoldingNothing() && VarGet(VAR_BEEHIVE_HONEY_AVAILABLE))
    {
        VarSet(VAR_BEEHIVE_HONEY_AVAILABLE, FALSE);
        SetPlayerHeldFood(ITEM_FOOD_HONEY);
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectBeehive);
        TalkClose();
    }
}

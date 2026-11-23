#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0185_LocationInteraction_InspectEllenHouseRefrigerator.mary.h"

void EventScript_0185_LocationInteraction_InspectEllenHouseRefrigerator(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectEllenHouseRefrigerator);
    TalkClose();
}

#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0151_LocationInteraction_InspectZackHouseRefrigerator.mary.h"

void EventScript_0151_LocationInteraction_InspectZackHouseRefrigerator(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectZackHouseRefrigerator);
    TalkClose();
}

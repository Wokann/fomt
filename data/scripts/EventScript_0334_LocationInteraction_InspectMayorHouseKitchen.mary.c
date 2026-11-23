#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0334_LocationInteraction_InspectMayorHouseKitchen.mary.h"

void EventScript_0334_LocationInteraction_InspectMayorHouseKitchen(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectMayorHouseKitchen);
    TalkClose();
}

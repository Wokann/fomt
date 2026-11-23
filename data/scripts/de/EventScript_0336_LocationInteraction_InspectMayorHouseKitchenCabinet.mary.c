#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0336_LocationInteraction_InspectMayorHouseKitchenCabinet.mary.h"

void EventScript_0336_LocationInteraction_InspectMayorHouseKitchenCabinet(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectMayorHouseKitchenCabinet);
    TalkClose();
}

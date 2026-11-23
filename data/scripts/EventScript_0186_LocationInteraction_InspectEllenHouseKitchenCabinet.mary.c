#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0186_LocationInteraction_InspectEllenHouseKitchenCabinet.mary.h"

void EventScript_0186_LocationInteraction_InspectEllenHouseKitchenCabinet(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectEllenHouseKitchenCabinet);
    TalkClose();
}

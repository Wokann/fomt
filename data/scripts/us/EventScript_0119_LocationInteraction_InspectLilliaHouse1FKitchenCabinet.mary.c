#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0119_LocationInteraction_InspectLilliaHouse1FKitchenCabinet.mary.h"

void EventScript_0119_LocationInteraction_InspectLilliaHouse1FKitchenCabinet(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLilliaHouse1FKitchenCabinet);
    TalkClose();
}

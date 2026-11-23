#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0438_LocationInteraction_InspectKaiRestaurantKitchenCabinet.mary.h"

void EventScript_0438_LocationInteraction_InspectKaiRestaurantKitchenCabinet(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectKaiRestaurantKitchenCabinet);
    TalkClose();
}

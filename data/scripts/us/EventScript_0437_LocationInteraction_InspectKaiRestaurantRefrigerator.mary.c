#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0437_LocationInteraction_InspectKaiRestaurantRefrigerator.mary.h"

void EventScript_0437_LocationInteraction_InspectKaiRestaurantRefrigerator(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectKaiRestaurantRefrigerator);
    TalkClose();
}

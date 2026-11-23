#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0117_LocationInteraction_InspectLilliaHouse1FKitchen.mary.h"

void EventScript_0117_LocationInteraction_InspectLilliaHouse1FKitchen(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLilliaHouse1FKitchen);
    TalkClose();
}

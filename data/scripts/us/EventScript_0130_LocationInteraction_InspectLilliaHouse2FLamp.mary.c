#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0130_LocationInteraction_InspectLilliaHouse2FLamp.mary.h"

void EventScript_0130_LocationInteraction_InspectLilliaHouse2FLamp(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLilliaHouse2FLamp);
    TalkClose();
}

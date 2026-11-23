#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0364_LocationInteraction_InspectTownNorthBench.mary.h"

void EventScript_0364_LocationInteraction_InspectTownNorthBench(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTownNorthBench);
    TalkClose();
}

#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0365_LocationInteraction_InspectGrapeVine.mary.h"

void EventScript_0365_LocationInteraction_InspectGrapeVine(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGrapeVine);
    TalkClose();
}

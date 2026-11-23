#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0100_LocationInteraction_InspectBeachBench.mary.h"

void EventScript_0100_LocationInteraction_InspectBeachBench(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBeachBench);
    TalkClose();
}

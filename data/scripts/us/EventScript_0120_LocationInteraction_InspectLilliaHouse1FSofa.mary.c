#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0120_LocationInteraction_InspectLilliaHouse1FSofa.mary.h"

void EventScript_0120_LocationInteraction_InspectLilliaHouse1FSofa(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLilliaHouse1FSofa);
    TalkClose();
}

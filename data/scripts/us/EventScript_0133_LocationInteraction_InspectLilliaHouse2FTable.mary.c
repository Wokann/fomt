#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0133_LocationInteraction_InspectLilliaHouse2FTable.mary.h"

void EventScript_0133_LocationInteraction_InspectLilliaHouse2FTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLilliaHouse2FTable);
    TalkClose();
}

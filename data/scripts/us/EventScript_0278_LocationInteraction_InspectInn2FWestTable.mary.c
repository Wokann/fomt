#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0278_LocationInteraction_InspectInn2FWestTable.mary.h"

void EventScript_0278_LocationInteraction_InspectInn2FWestTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInn2FWestTable);
    TalkClose();
}

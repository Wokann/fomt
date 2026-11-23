#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0245_LocationInteraction_InspectClinic2FWestTable.mary.h"

void EventScript_0245_LocationInteraction_InspectClinic2FWestTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic2FWestTable);
    TalkClose();
}

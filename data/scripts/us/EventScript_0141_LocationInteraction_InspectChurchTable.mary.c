#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0141_LocationInteraction_InspectChurchTable.mary.h"

void EventScript_0141_LocationInteraction_InspectChurchTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectChurchTable);
    TalkClose();
}

#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0355_LocationInteraction_InspectFarmhouseTable.mary.h"

void EventScript_0355_LocationInteraction_InspectFarmhouseTable(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectFarmhouseTable);
    TalkClose();
}

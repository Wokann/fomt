#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0337_LocationInteraction_InspectMayorHouseTable.mary.h"

void EventScript_0337_LocationInteraction_InspectMayorHouseTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectMayorHouseTable);
    TalkClose();
}

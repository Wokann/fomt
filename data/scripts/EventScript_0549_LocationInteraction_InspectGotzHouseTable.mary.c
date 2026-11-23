#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0549_LocationInteraction_InspectGotzHouseTable.mary.h"

void EventScript_0549_LocationInteraction_InspectGotzHouseTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHouseTable);
    TalkClose();
}

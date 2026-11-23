#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0303_LocationInteraction_InspectLibraryTable.mary.h"

void EventScript_0303_LocationInteraction_InspectLibraryTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLibraryTable);
    TalkClose();
}

#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0267_LocationInteraction_InspectInnBackRoomNortheastTable.mary.h"

void EventScript_0267_LocationInteraction_InspectInnBackRoomNortheastTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBackRoomNortheastTable);
    TalkClose();
}

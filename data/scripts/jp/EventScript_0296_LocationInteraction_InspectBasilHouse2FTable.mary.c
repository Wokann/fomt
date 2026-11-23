#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0296_LocationInteraction_InspectBasilHouse2FTable.mary.h"

void EventScript_0296_LocationInteraction_InspectBasilHouse2FTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBasilHouse2FTable);
    TalkClose();
}

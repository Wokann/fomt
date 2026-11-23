#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0291_LocationInteraction_InspectBasilHouse1FTable.mary.h"

void EventScript_0291_LocationInteraction_InspectBasilHouse1FTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBasilHouse1FTable);
    TalkClose();
}

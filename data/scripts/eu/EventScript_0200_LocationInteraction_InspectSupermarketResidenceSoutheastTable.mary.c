#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0200_LocationInteraction_InspectSupermarketResidenceSoutheastTable.mary.h"

void EventScript_0200_LocationInteraction_InspectSupermarketResidenceSoutheastTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketResidenceSoutheastTable);
    TalkClose();
}

#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0193_LocationInteraction_InspectSupermarketResidenceNorthwestTable.mary.h"

void EventScript_0193_LocationInteraction_InspectSupermarketResidenceNorthwestTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketResidenceNorthwestTable);
    TalkClose();
}

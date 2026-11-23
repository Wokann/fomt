#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0198_LocationInteraction_InspectSupermarketResidenceRefrigerator.mary.h"

void EventScript_0198_LocationInteraction_InspectSupermarketResidenceRefrigerator(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketResidenceRefrigerator);
    TalkClose();
}

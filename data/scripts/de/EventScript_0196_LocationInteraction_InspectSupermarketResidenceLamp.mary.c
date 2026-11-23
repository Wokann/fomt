#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0196_LocationInteraction_InspectSupermarketResidenceLamp.mary.h"

void EventScript_0196_LocationInteraction_InspectSupermarketResidenceLamp(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketResidenceLamp);
    TalkClose();
}

#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0190_LocationInteraction_InspectSupermarketResidenceBed.mary.h"

void EventScript_0190_LocationInteraction_InspectSupermarketResidenceBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketResidenceBed);
    TalkClose();
}

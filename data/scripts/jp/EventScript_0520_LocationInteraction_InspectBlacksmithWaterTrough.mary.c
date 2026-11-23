#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0520_LocationInteraction_InspectBlacksmithWaterTrough.mary.h"

void EventScript_0520_LocationInteraction_InspectBlacksmithWaterTrough(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithWaterTrough);
    TalkClose();
}

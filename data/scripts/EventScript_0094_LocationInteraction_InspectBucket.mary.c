#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0094_LocationInteraction_InspectBucket.mary.h"

void EventScript_0094_LocationInteraction_InspectBucket(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBucket);
    TalkClose();
}

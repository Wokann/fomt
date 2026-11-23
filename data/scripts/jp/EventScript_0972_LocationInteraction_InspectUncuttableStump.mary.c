#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0972_LocationInteraction_InspectUncuttableStump.mary.h"

void EventScript_0972_LocationInteraction_InspectUncuttableStump(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectUncuttableStump);
    TalkClose();
}

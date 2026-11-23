#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0159_LocationInteraction_InspectStable.mary.h"

void EventScript_0159_LocationInteraction_InspectStable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectStable);
    TalkClose();
}

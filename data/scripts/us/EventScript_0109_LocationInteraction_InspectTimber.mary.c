#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0109_LocationInteraction_InspectTimber.mary.h"

void EventScript_0109_LocationInteraction_InspectTimber(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTimber);
    TalkClose();
}

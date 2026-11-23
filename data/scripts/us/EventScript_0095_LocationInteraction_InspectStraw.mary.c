#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0095_LocationInteraction_InspectStraw.mary.h"

void EventScript_0095_LocationInteraction_InspectStraw(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectStraw);
    TalkClose();
}

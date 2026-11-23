#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0257_LocationInteraction_InspectDresser.mary.h"

void EventScript_0257_LocationInteraction_InspectDresser(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectDresser);
    TalkClose();
}

#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0145_LocationInteraction_InspectZackHouseBarrel.mary.h"

void EventScript_0145_LocationInteraction_InspectZackHouseBarrel(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectZackHouseBarrel);
    TalkClose();
}

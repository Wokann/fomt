#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0542_LocationInteraction_InspectGotzHouseBed.mary.h"

void EventScript_0542_LocationInteraction_InspectGotzHouseBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHouseBed);
    TalkClose();
}

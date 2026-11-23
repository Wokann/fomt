#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0546_LocationInteraction_InspectGotzHousePlant.mary.h"

void EventScript_0546_LocationInteraction_InspectGotzHousePlant(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHousePlant);
    TalkClose();
}

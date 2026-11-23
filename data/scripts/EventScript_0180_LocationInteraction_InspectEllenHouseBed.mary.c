#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0180_LocationInteraction_InspectEllenHouseBed.mary.h"

void EventScript_0180_LocationInteraction_InspectEllenHouseBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectEllenHouseBed);
    TalkClose();
}

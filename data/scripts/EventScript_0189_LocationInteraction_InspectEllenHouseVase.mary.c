#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0189_LocationInteraction_InspectEllenHouseVase.mary.h"

void EventScript_0189_LocationInteraction_InspectEllenHouseVase(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectEllenHouseVase);
    TalkClose();
}

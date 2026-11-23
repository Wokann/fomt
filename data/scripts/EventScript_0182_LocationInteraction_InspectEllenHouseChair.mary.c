#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0182_LocationInteraction_InspectEllenHouseChair.mary.h"

void EventScript_0182_LocationInteraction_InspectEllenHouseChair(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectEllenHouseChair);
    TalkClose();
}

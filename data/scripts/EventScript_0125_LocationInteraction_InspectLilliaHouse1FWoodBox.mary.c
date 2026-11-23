#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0125_LocationInteraction_InspectLilliaHouse1FWoodBox.mary.h"

void EventScript_0125_LocationInteraction_InspectLilliaHouse1FWoodBox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLilliaHouse1FWoodBox);
    TalkClose();
}

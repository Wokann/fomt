#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0152_LocationInteraction_InspectZackHouseWoodBox.mary.h"

void EventScript_0152_LocationInteraction_InspectZackHouseWoodBox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectZackHouseWoodBox);
    TalkClose();
}

#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0367_LocationInteraction_InspectStreetLamp.mary.h"

void EventScript_0367_LocationInteraction_InspectStreetLamp(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectStreetLamp);
    TalkClose();
}

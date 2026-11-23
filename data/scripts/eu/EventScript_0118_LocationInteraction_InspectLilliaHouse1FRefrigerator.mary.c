#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0118_LocationInteraction_InspectLilliaHouse1FRefrigerator.mary.h"

void EventScript_0118_LocationInteraction_InspectLilliaHouse1FRefrigerator(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLilliaHouse1FRefrigerator);
    TalkClose();
}

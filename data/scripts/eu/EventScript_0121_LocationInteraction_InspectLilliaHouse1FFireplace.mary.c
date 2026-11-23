#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0121_LocationInteraction_InspectLilliaHouse1FFireplace.mary.h"

void EventScript_0121_LocationInteraction_InspectLilliaHouse1FFireplace(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLilliaHouse1FFireplace);
    TalkClose();
}

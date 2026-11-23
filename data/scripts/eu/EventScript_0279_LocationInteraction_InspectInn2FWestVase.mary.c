#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0279_LocationInteraction_InspectInn2FWestVase.mary.h"

void EventScript_0279_LocationInteraction_InspectInn2FWestVase(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInn2FWestVase);
    TalkClose();
}

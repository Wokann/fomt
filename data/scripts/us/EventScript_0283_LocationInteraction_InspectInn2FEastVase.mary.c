#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0283_LocationInteraction_InspectInn2FEastVase.mary.h"

void EventScript_0283_LocationInteraction_InspectInn2FEastVase(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInn2FEastVase);
    TalkClose();
}

#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0276_LocationInteraction_InspectInn2FWestBed.mary.h"

void EventScript_0276_LocationInteraction_InspectInn2FWestBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInn2FWestBed);
    TalkClose();
}

#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0280_LocationInteraction_InspectInn2FEastBed.mary.h"

void EventScript_0280_LocationInteraction_InspectInn2FEastBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInn2FEastBed);
    TalkClose();
}

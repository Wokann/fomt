#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0241_LocationInteraction_InspectClinic2FWestBed.mary.h"

void EventScript_0241_LocationInteraction_InspectClinic2FWestBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic2FWestBed);
    TalkClose();
}

#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0294_LocationInteraction_InspectBasilHouse2FBed.mary.h"

void EventScript_0294_LocationInteraction_InspectBasilHouse2FBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBasilHouse2FBed);
    TalkClose();
}

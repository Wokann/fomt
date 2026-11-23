#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0333_LocationInteraction_InspectMayorHouseClock.mary.h"

void EventScript_0333_LocationInteraction_InspectMayorHouseClock(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectMayorHouseClock);
    TalkClose();
}

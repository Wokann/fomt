#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0330_LocationInteraction_InspectMayorHouseBed.mary.h"

void EventScript_0330_LocationInteraction_InspectMayorHouseBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectMayorHouseBed);
    TalkClose();
}

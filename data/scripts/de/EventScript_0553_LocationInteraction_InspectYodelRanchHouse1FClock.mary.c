#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0553_LocationInteraction_InspectYodelRanchHouse1FClock.mary.h"

void EventScript_0553_LocationInteraction_InspectYodelRanchHouse1FClock(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchHouse1FClock);
    TalkClose();
}

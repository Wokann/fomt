#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0567_LocationInteraction_InspectYodelRanchHouse2FDesk.mary.h"

void EventScript_0567_LocationInteraction_InspectYodelRanchHouse2FDesk(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchHouse2FDesk);
    TalkClose();
}

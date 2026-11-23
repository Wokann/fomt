#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0565_LocationInteraction_InspectYodelRanchHouse2FChair.mary.h"

void EventScript_0565_LocationInteraction_InspectYodelRanchHouse2FChair(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchHouse2FChair);
    TalkClose();
}

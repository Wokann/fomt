#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0552_LocationInteraction_InspectYodelRanchHouse1FChair.mary.h"

void EventScript_0552_LocationInteraction_InspectYodelRanchHouse1FChair(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchHouse1FChair);
    TalkClose();
}

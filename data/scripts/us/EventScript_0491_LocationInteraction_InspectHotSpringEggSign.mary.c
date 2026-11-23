#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0491_LocationInteraction_InspectHotSpringEggSign.mary.h"

void EventScript_0491_LocationInteraction_InspectHotSpringEggSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHotSpringEggSign);
    TalkClose();
}

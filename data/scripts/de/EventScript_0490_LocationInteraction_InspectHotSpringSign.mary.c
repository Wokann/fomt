#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0490_LocationInteraction_InspectHotSpringSign.mary.h"

void EventScript_0490_LocationInteraction_InspectHotSpringSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHotSpringSign);
    TalkClose();
}

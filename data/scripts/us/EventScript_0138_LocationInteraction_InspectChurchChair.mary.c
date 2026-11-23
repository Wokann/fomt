#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0138_LocationInteraction_InspectChurchChair.mary.h"

void EventScript_0138_LocationInteraction_InspectChurchChair(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectChurchChair);
    TalkClose();
}

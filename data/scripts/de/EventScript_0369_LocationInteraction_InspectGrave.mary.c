#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0369_LocationInteraction_InspectGrave.mary.h"

void EventScript_0369_LocationInteraction_InspectGrave(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGrave);
    TalkClose();
}

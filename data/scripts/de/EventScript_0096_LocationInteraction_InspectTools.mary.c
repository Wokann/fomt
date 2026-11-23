#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0096_LocationInteraction_InspectTools.mary.h"

void EventScript_0096_LocationInteraction_InspectTools(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTools);
    TalkClose();
}

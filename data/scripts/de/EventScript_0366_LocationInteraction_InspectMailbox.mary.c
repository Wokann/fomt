#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0366_LocationInteraction_InspectMailbox.mary.h"

void EventScript_0366_LocationInteraction_InspectMailbox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectMailbox);
    TalkClose();
}

#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0174_LocationInteraction_InspectTree.mary.h"

void EventScript_0174_LocationInteraction_InspectTree(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTree);
    TalkClose();
}

#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0518_LocationInteraction_InspectBlacksmithTable.mary.h"

void EventScript_0518_LocationInteraction_InspectBlacksmithTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithTable);
    TalkClose();
}

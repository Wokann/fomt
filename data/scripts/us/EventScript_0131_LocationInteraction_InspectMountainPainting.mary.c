#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0131_LocationInteraction_InspectMountainPainting.mary.h"

void EventScript_0131_LocationInteraction_InspectMountainPainting(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectMountainPainting);
    TalkClose();
}

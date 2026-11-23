#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0970_LocationInteraction_InspectLargeStoneRequiresHigherHammerLevel.mary.h"

void EventScript_0970_LocationInteraction_InspectLargeStoneRequiresHigherHammerLevel(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLargeStoneRequiresHigherHammerLevel);
    TalkClose();
}

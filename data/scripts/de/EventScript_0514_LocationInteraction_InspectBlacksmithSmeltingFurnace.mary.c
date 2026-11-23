#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0514_LocationInteraction_InspectBlacksmithSmeltingFurnace.mary.h"

void EventScript_0514_LocationInteraction_InspectBlacksmithSmeltingFurnace(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithSmeltingFurnace);
    TalkClose();
}

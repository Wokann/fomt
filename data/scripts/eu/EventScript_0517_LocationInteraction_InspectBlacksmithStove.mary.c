#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0517_LocationInteraction_InspectBlacksmithStove.mary.h"

void EventScript_0517_LocationInteraction_InspectBlacksmithStove(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithStove);
    TalkClose();
}

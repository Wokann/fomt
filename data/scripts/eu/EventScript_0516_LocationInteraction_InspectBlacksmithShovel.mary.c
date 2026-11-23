#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0516_LocationInteraction_InspectBlacksmithShovel.mary.h"

void EventScript_0516_LocationInteraction_InspectBlacksmithShovel(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithShovel);
    TalkClose();
}

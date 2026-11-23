#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0192_LocationInteraction_InspectSupermarketResidenceChair.mary.h"

void EventScript_0192_LocationInteraction_InspectSupermarketResidenceChair(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketResidenceChair);
    TalkClose();
}

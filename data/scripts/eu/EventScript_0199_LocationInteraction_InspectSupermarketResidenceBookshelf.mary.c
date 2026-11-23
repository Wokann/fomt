#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0199_LocationInteraction_InspectSupermarketResidenceBookshelf.mary.h"

void EventScript_0199_LocationInteraction_InspectSupermarketResidenceBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketResidenceBookshelf);
    TalkClose();
}

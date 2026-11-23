#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0127_LocationInteraction_InspectLilliaHouse2FBookshelf.mary.h"

void EventScript_0127_LocationInteraction_InspectLilliaHouse2FBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLilliaHouse2FBookshelf);
    TalkClose();
}

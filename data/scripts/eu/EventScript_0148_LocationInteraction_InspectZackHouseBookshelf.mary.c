#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0148_LocationInteraction_InspectZackHouseBookshelf.mary.h"

void EventScript_0148_LocationInteraction_InspectZackHouseBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectZackHouseBookshelf);
    TalkClose();
}

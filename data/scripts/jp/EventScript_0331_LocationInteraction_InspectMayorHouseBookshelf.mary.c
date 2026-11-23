#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0331_LocationInteraction_InspectMayorHouseBookshelf.mary.h"

void EventScript_0331_LocationInteraction_InspectMayorHouseBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectMayorHouseBookshelf);
    TalkClose();
}

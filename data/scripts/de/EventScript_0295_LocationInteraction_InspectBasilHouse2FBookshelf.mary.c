#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0295_LocationInteraction_InspectBasilHouse2FBookshelf.mary.h"

void EventScript_0295_LocationInteraction_InspectBasilHouse2FBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBasilHouse2FBookshelf);
    TalkClose();
}

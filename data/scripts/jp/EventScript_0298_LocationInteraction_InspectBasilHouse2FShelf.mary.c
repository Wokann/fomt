#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0298_LocationInteraction_InspectBasilHouse2FShelf.mary.h"

void EventScript_0298_LocationInteraction_InspectBasilHouse2FShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBasilHouse2FShelf);
    TalkClose();
}

#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0204_LocationInteraction_InspectSupermarketEastShelf.mary.h"

void EventScript_0204_LocationInteraction_InspectSupermarketEastShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketEastShelf);
    TalkClose();
}

#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0203_LocationInteraction_InspectSupermarketWestShelf.mary.h"

void EventScript_0203_LocationInteraction_InspectSupermarketWestShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketWestShelf);
    TalkClose();
}

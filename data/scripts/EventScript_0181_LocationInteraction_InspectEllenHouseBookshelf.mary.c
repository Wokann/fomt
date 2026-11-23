#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0181_LocationInteraction_InspectEllenHouseBookshelf.mary.h"

void EventScript_0181_LocationInteraction_InspectEllenHouseBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectEllenHouseBookshelf);
    TalkClose();
}

#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0253_LocationInteraction_InspectLiquorShelf.mary.h"

void EventScript_0253_LocationInteraction_InspectLiquorShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLiquorShelf);
    TalkClose();
}

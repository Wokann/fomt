#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0512_LocationInteraction_InspectBlacksmithBookshelf.mary.h"

void EventScript_0512_LocationInteraction_InspectBlacksmithBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithBookshelf);
    TalkClose();
}

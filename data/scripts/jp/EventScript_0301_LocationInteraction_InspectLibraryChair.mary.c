#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0301_LocationInteraction_InspectLibraryChair.mary.h"

void EventScript_0301_LocationInteraction_InspectLibraryChair(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLibraryChair);
    TalkClose();
}

#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0302_LocationInteraction_InspectLibrary1FCounter.mary.h"

void EventScript_0302_LocationInteraction_InspectLibrary1FCounter(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLibrary1FCounter);
    TalkClose();
}

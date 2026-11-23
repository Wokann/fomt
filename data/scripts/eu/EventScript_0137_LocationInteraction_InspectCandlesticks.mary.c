#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0137_LocationInteraction_InspectCandlesticks.mary.h"

void EventScript_0137_LocationInteraction_InspectCandlesticks(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectCandlesticks);
    TalkClose();
}

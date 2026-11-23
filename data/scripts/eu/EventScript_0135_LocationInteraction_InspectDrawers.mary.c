#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0135_LocationInteraction_InspectDrawers.mary.h"

void EventScript_0135_LocationInteraction_InspectDrawers(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectDrawers);
    TalkClose();
}

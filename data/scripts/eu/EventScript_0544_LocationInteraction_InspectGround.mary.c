#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0544_LocationInteraction_InspectGround.mary.h"

void EventScript_0544_LocationInteraction_InspectGround(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGround);
    TalkClose();
}

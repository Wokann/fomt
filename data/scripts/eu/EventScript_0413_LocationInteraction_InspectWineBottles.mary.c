#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0413_LocationInteraction_InspectWineBottles.mary.h"

void EventScript_0413_LocationInteraction_InspectWineBottles(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectWineBottles);
    TalkClose();
}

#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0420_LocationInteraction_InspectWineRack.mary.h"

void EventScript_0420_LocationInteraction_InspectWineRack(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectWineRack);
    TalkClose();
}

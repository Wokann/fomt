#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0103_LocationInteraction_InspectBoat.mary.h"

void EventScript_0103_LocationInteraction_InspectBoat(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBoat);
    TalkClose();
}

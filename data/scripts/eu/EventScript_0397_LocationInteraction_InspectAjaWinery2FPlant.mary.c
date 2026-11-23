#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0397_LocationInteraction_InspectAjaWinery2FPlant.mary.h"

void EventScript_0397_LocationInteraction_InspectAjaWinery2FPlant(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWinery2FPlant);
    TalkClose();
}

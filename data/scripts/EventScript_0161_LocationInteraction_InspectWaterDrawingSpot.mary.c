#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0161_LocationInteraction_InspectWaterDrawingSpot.mary.h"

void EventScript_0161_LocationInteraction_InspectWaterDrawingSpot(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectWaterDrawingSpot);
    TalkClose();
}

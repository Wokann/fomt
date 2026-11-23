#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0535_LocationInteraction_InspectTownCottageChair.mary.h"

void EventScript_0535_LocationInteraction_InspectTownCottageChair(void)
{
    TalkOpen();
#if defined(REGION_JP) || defined(REGION_DE)
    TalkMessage(gText_LocationInteraction_InspectTownCottageChair);
#else
    TalkAppendMessage(gText_LocationInteraction_InspectTownCottageChair);
#endif
    TalkClose();
}

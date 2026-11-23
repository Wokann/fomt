#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0539_LocationInteraction_InspectTownCottageDesk.mary.h"

void EventScript_0539_LocationInteraction_InspectTownCottageDesk(void)
{
    TalkOpen();
#if defined(REGION_JP) || defined(REGION_DE)
    TalkMessage(gText_LocationInteraction_InspectTownCottageDesk);
#else
    TalkAppendMessage(gText_LocationInteraction_InspectTownCottageDesk);
#endif
    TalkClose();
}

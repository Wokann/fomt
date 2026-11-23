#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0539_LocationInteraction_InspectTownCottageDesk.mary.h"

void EventScript_0539_LocationInteraction_InspectTownCottageDesk(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectTownCottageDesk);
    TalkClose();
}

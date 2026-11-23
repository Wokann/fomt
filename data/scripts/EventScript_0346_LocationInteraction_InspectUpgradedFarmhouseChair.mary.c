#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0346_LocationInteraction_InspectUpgradedFarmhouseChair.mary.h"

void EventScript_0346_LocationInteraction_InspectUpgradedFarmhouseChair(void)
{
    TalkOpen();
#if defined(REGION_JP)
    TalkMessage(gText_LocationInteraction_InspectUpgradedFarmhouseChair);
#else
    TalkAppendMessage(gText_LocationInteraction_InspectUpgradedFarmhouseChair);
#endif
    TalkClose();
}

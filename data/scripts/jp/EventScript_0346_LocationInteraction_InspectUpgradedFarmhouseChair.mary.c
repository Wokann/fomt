#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0346_LocationInteraction_InspectUpgradedFarmhouseChair.mary.h"

void EventScript_0346_LocationInteraction_InspectUpgradedFarmhouseChair(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectUpgradedFarmhouseChair);
    TalkClose();
}

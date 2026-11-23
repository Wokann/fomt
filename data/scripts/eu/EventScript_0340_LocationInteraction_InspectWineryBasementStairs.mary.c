#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0340_LocationInteraction_InspectWineryBasementStairs.mary.h"

void EventScript_0340_LocationInteraction_InspectWineryBasementStairs(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectWineryBasementStairs);
    TalkClose();
}

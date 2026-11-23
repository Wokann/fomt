#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0505_LocationInteraction_InspectNorthSideOfMineralTownSouth.mary.h"

void EventScript_0505_LocationInteraction_InspectNorthSideOfMineralTownSouth(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectNorthSideOfMineralTownSouth);
    TalkClose();
}

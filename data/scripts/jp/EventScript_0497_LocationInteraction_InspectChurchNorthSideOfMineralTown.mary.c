#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0497_LocationInteraction_InspectChurchNorthSideOfMineralTown.mary.h"

void EventScript_0497_LocationInteraction_InspectChurchNorthSideOfMineralTown(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectChurchNorthSideOfMineralTown);
    TalkClose();
}

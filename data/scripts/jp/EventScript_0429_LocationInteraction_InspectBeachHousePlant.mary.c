#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0429_LocationInteraction_InspectBeachHousePlant.mary.h"

void EventScript_0429_LocationInteraction_InspectBeachHousePlant(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectBeachHousePlant);
    TalkClose();
}

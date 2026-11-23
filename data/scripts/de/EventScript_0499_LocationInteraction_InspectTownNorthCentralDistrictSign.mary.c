#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0499_LocationInteraction_InspectTownNorthCentralDistrictSign.mary.h"

void EventScript_0499_LocationInteraction_InspectTownNorthCentralDistrictSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTownNorthCentralDistrictSign);
    TalkClose();
}

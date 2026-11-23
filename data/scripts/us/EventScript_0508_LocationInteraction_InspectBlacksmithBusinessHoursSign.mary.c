#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0508_LocationInteraction_InspectBlacksmithBusinessHoursSign.mary.h"

void EventScript_0508_LocationInteraction_InspectBlacksmithBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithBusinessHoursSign);
    TalkClose();
}

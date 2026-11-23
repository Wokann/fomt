#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0504_LocationInteraction_InspectPoultryFarmBusinessHoursSign.mary.h"

void EventScript_0504_LocationInteraction_InspectPoultryFarmBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectPoultryFarmBusinessHoursSign);
    TalkClose();
}

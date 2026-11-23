#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0500_LocationInteraction_InspectClinicBusinessHoursSign.mary.h"

void EventScript_0500_LocationInteraction_InspectClinicBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinicBusinessHoursSign);
    TalkClose();
}

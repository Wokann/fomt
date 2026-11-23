#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0501_LocationInteraction_InspectInnBusinessHoursSign.mary.h"

void EventScript_0501_LocationInteraction_InspectInnBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBusinessHoursSign);
    TalkClose();
}

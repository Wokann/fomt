#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0510_LocationInteraction_InspectYodelRanchBusinessHoursSign.mary.h"

void EventScript_0510_LocationInteraction_InspectYodelRanchBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchBusinessHoursSign);
    TalkClose();
}

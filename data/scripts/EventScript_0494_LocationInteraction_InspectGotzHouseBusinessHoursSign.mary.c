#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0494_LocationInteraction_InspectGotzHouseBusinessHoursSign.mary.h"

void EventScript_0494_LocationInteraction_InspectGotzHouseBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHouseBusinessHoursSign);
    TalkClose();
}

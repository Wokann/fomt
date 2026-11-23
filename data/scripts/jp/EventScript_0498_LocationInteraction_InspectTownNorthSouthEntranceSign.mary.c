#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0498_LocationInteraction_InspectTownNorthSouthEntranceSign.mary.h"

void EventScript_0498_LocationInteraction_InspectTownNorthSouthEntranceSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTownNorthSouthEntranceSign);
    TalkClose();
}

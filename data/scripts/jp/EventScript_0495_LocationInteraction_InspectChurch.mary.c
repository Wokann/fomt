#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0495_LocationInteraction_InspectChurch.mary.h"

void EventScript_0495_LocationInteraction_InspectChurch(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectChurch);
    TalkClose();
}

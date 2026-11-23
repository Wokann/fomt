#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0243_LocationInteraction_InspectDesk.mary.h"

void EventScript_0243_LocationInteraction_InspectDesk(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectDesk);
    TalkClose();
}

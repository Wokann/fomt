#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0116_LocationInteraction_InspectLilliaHouse1FChair.mary.h"

void EventScript_0116_LocationInteraction_InspectLilliaHouse1FChair(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLilliaHouse1FChair);
    TalkClose();
}

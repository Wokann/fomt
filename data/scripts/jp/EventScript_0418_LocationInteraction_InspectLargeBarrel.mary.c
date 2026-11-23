#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0418_LocationInteraction_InspectLargeBarrel.mary.h"

void EventScript_0418_LocationInteraction_InspectLargeBarrel(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLargeBarrel);
    TalkClose();
}

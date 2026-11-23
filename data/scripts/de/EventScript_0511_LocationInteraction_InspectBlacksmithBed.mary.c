#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0511_LocationInteraction_InspectBlacksmithBed.mary.h"

void EventScript_0511_LocationInteraction_InspectBlacksmithBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithBed);
    TalkClose();
}

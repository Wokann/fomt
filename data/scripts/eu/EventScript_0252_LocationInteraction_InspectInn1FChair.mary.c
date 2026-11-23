#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0252_LocationInteraction_InspectInn1FChair.mary.h"

void EventScript_0252_LocationInteraction_InspectInn1FChair(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInn1FChair);
    TalkClose();
}

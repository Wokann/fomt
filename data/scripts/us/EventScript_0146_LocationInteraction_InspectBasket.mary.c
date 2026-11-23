#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0146_LocationInteraction_InspectBasket.mary.h"

void EventScript_0146_LocationInteraction_InspectBasket(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBasket);
    TalkClose();
}

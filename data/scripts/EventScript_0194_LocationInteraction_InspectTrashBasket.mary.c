#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0194_LocationInteraction_InspectTrashBasket.mary.h"

void EventScript_0194_LocationInteraction_InspectTrashBasket(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTrashBasket);
    TalkClose();
}

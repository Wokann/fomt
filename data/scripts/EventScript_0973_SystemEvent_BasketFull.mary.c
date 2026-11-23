#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0973_SystemEvent_BasketFull.mary.h"

void EventScript_0973_SystemEvent_BasketFull(void)
{
    TalkOpen();
    TalkMessage(gText_SystemEvent_BasketFull);
    TalkClose();
}

#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0386_LocationInteraction_InspectAjaWinery1FRefrigerator.mary.h"

void EventScript_0386_LocationInteraction_InspectAjaWinery1FRefrigerator(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWinery1FRefrigerator);
    TalkClose();
}

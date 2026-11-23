#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0289_LocationInteraction_InspectBasilHouse1FRefrigerator.mary.h"

void EventScript_0289_LocationInteraction_InspectBasilHouse1FRefrigerator(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBasilHouse1FRefrigerator);
    TalkClose();
}

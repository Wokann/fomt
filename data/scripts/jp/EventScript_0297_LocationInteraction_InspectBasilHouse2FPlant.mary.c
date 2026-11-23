#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0297_LocationInteraction_InspectBasilHouse2FPlant.mary.h"

void EventScript_0297_LocationInteraction_InspectBasilHouse2FPlant(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBasilHouse2FPlant);
    TalkClose();
}

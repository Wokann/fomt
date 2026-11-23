#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0299_LocationInteraction_InspectBasilHouse2FFireplace.mary.h"

void EventScript_0299_LocationInteraction_InspectBasilHouse2FFireplace(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBasilHouse2FFireplace);
    TalkClose();
}

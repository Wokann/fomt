#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0286_LocationInteraction_InspectBasilHouse1FChair.mary.h"

void EventScript_0286_LocationInteraction_InspectBasilHouse1FChair(void)
{
    TalkOpen();
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    TalkAppendMessage(gText_LocationInteraction_InspectBasilHouse1FChair);
#elif defined(REGION_DE)
    TalkMessage(gText_LocationInteraction_InspectBasilHouse1FChair);
#endif
    TalkClose();
}

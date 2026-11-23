#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0149_LocationInteraction_InspectZackHouseKitchen.mary.h"

void EventScript_0149_LocationInteraction_InspectZackHouseKitchen(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectZackHouseKitchen);
    TalkClose();
}

#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0545_LocationInteraction_InspectGotzHouseKitchen.mary.h"

void EventScript_0545_LocationInteraction_InspectGotzHouseKitchen(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHouseKitchen);
    TalkClose();
}

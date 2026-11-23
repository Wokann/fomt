#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0439_LocationInteraction_InspectKaiRestaurantTable.mary.h"

void EventScript_0439_LocationInteraction_InspectKaiRestaurantTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectKaiRestaurantTable);
    TalkClose();
}

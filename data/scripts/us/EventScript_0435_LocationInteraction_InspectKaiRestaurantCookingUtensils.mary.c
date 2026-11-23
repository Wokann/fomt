#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0435_LocationInteraction_InspectKaiRestaurantCookingUtensils.mary.h"

void EventScript_0435_LocationInteraction_InspectKaiRestaurantCookingUtensils(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectKaiRestaurantCookingUtensils);
    TalkClose();
}

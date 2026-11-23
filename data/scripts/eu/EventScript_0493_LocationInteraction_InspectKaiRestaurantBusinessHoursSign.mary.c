#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0493_LocationInteraction_InspectKaiRestaurantBusinessHoursSign.mary.h"

void EventScript_0493_LocationInteraction_InspectKaiRestaurantBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectKaiRestaurantBusinessHoursSign);
    TalkClose();
}

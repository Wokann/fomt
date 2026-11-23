#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0436_LocationInteraction_InspectKaiRestaurantPoster.mary.h"

void EventScript_0436_LocationInteraction_InspectKaiRestaurantPoster(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectKaiRestaurantPoster);
    TalkClose();
}

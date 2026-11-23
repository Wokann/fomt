#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0208_LocationInteraction_InspectSupermarketPoster.mary.h"

void EventScript_0208_LocationInteraction_InspectSupermarketPoster(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketPoster);
    TalkClose();
}

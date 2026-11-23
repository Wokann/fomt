#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0207_LocationInteraction_InspectAdvertisement.mary.h"

void EventScript_0207_LocationInteraction_InspectAdvertisement(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAdvertisement);
    TalkClose();
}

#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0195_LocationInteraction_InspectSupermarketResidenceKitchen.mary.h"

void EventScript_0195_LocationInteraction_InspectSupermarketResidenceKitchen(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketResidenceKitchen);
    TalkClose();
}

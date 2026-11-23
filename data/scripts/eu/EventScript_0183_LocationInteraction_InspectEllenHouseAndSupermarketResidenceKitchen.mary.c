#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0183_LocationInteraction_InspectEllenHouseAndSupermarketResidenceKitchen.mary.h"

void EventScript_0183_LocationInteraction_InspectEllenHouseAndSupermarketResidenceKitchen(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectEllenHouseAndSupermarketResidenceKitchen);
    TalkClose();
}

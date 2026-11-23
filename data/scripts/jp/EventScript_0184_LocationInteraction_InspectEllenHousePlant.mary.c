#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0184_LocationInteraction_InspectEllenHousePlant.mary.h"

void EventScript_0184_LocationInteraction_InspectEllenHousePlant(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectEllenHousePlant);
    TalkClose();
}

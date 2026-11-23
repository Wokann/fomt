#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0261_LocationInteraction_InspectBigKitchen.mary.h"

void EventScript_0261_LocationInteraction_InspectBigKitchen(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBigKitchen);
    TalkClose();
}

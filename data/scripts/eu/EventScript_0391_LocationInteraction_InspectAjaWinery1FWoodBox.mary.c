#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0391_LocationInteraction_InspectAjaWinery1FWoodBox.mary.h"

void EventScript_0391_LocationInteraction_InspectAjaWinery1FWoodBox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWinery1FWoodBox);
    TalkClose();
}

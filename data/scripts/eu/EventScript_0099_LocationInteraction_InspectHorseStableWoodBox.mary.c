#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0099_LocationInteraction_InspectHorseStableWoodBox.mary.h"

void EventScript_0099_LocationInteraction_InspectHorseStableWoodBox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHorseStableWoodBox);
    TalkClose();
}

#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0326_LocationInteraction_InspectHarvestSpritesHutPlant.mary.h"

void EventScript_0326_LocationInteraction_InspectHarvestSpritesHutPlant(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHarvestSpritesHutPlant);
    TalkClose();
}

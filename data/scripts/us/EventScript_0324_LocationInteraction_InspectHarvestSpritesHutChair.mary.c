#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0324_LocationInteraction_InspectHarvestSpritesHutChair.mary.h"

void EventScript_0324_LocationInteraction_InspectHarvestSpritesHutChair(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHarvestSpritesHutChair);
    TalkClose();
}

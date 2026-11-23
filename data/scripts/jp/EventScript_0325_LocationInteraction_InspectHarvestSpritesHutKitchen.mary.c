#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0325_LocationInteraction_InspectHarvestSpritesHutKitchen.mary.h"

void EventScript_0325_LocationInteraction_InspectHarvestSpritesHutKitchen(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHarvestSpritesHutKitchen);
    TalkClose();
}

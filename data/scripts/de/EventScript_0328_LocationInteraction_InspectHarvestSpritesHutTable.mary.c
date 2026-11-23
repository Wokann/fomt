#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0328_LocationInteraction_InspectHarvestSpritesHutTable.mary.h"

void EventScript_0328_LocationInteraction_InspectHarvestSpritesHutTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHarvestSpritesHutTable);
    TalkClose();
}

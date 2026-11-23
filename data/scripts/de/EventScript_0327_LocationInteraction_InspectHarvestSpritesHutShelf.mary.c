#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0327_LocationInteraction_InspectHarvestSpritesHutShelf.mary.h"

void EventScript_0327_LocationInteraction_InspectHarvestSpritesHutShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHarvestSpritesHutShelf);
    TalkClose();
}

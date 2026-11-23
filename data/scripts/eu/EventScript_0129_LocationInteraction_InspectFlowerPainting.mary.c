#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0129_LocationInteraction_InspectFlowerPainting.mary.h"

void EventScript_0129_LocationInteraction_InspectFlowerPainting(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectFlowerPainting);
    TalkClose();
}

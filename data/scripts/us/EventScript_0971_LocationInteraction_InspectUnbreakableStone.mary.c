#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0971_LocationInteraction_InspectUnbreakableStone.mary.h"

void EventScript_0971_LocationInteraction_InspectUnbreakableStone(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectUnbreakableStone);
    TalkClose();
}

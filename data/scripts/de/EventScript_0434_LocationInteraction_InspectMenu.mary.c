#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0434_LocationInteraction_InspectMenu.mary.h"

void EventScript_0434_LocationInteraction_InspectMenu(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectMenu);
    TalkClose();
}

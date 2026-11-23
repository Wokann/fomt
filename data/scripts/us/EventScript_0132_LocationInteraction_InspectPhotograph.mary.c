#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0132_LocationInteraction_InspectPhotograph.mary.h"

void EventScript_0132_LocationInteraction_InspectPhotograph(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectPhotograph);
    TalkClose();
}

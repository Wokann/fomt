#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0101_LocationInteraction_InspectParasol.mary.h"

void EventScript_0101_LocationInteraction_InspectParasol(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectParasol);
    TalkClose();
}

#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0398_LocationInteraction_InspectAjaWinery2FTable.mary.h"

void EventScript_0398_LocationInteraction_InspectAjaWinery2FTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWinery2FTable);
    TalkClose();
}

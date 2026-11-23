#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0270_LocationInteraction_InspectInn1FTable.mary.h"

void EventScript_0270_LocationInteraction_InspectInn1FTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInn1FTable);
    TalkClose();
}

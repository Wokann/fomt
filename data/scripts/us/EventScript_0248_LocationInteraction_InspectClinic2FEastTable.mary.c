#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0248_LocationInteraction_InspectClinic2FEastTable.mary.h"

void EventScript_0248_LocationInteraction_InspectClinic2FEastTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic2FEastTable);
    TalkClose();
}

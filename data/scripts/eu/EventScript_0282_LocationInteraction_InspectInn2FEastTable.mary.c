#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0282_LocationInteraction_InspectInn2FEastTable.mary.h"

void EventScript_0282_LocationInteraction_InspectInn2FEastTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInn2FEastTable);
    TalkClose();
}

#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0246_LocationInteraction_InspectClinic2FPlant.mary.h"

void EventScript_0246_LocationInteraction_InspectClinic2FPlant(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic2FPlant);
    TalkClose();
}

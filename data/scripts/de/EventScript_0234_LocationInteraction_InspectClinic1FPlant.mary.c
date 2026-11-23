#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0234_LocationInteraction_InspectClinic1FPlant.mary.h"

void EventScript_0234_LocationInteraction_InspectClinic1FPlant(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic1FPlant);
    TalkClose();
}

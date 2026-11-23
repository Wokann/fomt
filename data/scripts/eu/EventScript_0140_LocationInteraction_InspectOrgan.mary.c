#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0140_LocationInteraction_InspectOrgan.mary.h"

void EventScript_0140_LocationInteraction_InspectOrgan(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectOrgan);
    TalkClose();
}

#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0522_LocationInteraction_InspectTownSouthMailbox.mary.h"

void EventScript_0522_LocationInteraction_InspectTownSouthMailbox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTownSouthMailbox);
    TalkClose();
}
